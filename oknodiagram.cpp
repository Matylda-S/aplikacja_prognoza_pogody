#include "oknodiagram.hh"
/*!
* \file
* \brief Definicja metody klasy OknoDiagram
*
* Zawiera definicję metod klasy OknoDiagram
*/
/*!
 * \brief Metoda inicjalizujaca obiekt tej klasy

 * \param parent rodzic
 */
#include "ui_oknodiagram.h"
OknoDiagram::OknoDiagram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoDialog)
{
    ui->setupUi(this);
    m_graphicsView = new QGraphicsView(this);

    m_chartView = new QChartView(this);
    m_chart = new QChart();
    m_series = new QLineSeries();


}

OknoDiagram::~OknoDiagram()
{
    delete ui;
}
/*!
 * \brief Metoda rysuje wykres
 * rysuje wykres zalezności temperatury od daty
 * \param temp[7] tablica zawieraja prognozowana temperature na 7 dni
 * \param data[] tablica zawierajaca daty najmbliższych 7 dni
 */
void OknoDiagram::wykres(double temp[],QDateTime data[]){

    for (int i = 0; i < 7; i++) {
        QDateTime dateTime = data[i];
        m_series->append(dateTime.toMSecsSinceEpoch(), temp[i]);

    }

    m_chart->addSeries(m_series);
    m_chart->createDefaultAxes();

    m_chartView->setChart(m_chart);
    m_chart->setTitle("Temperatura");

        QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(7);
        axisX->setTitleText("Data");
        axisX->setFormat("dd.MM");
        m_chart->setAxisX(axisX, m_series);


    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Temperatura");
    axisY->setLabelFormat("%.1f");
    m_chart->setAxisY(axisY, m_series);
m_series->setColor(Qt::red);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_chartView);
    setLayout(layout);
}
