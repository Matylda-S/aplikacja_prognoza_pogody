#ifndef OKNODIAGRAM_HH
#define OKNODIAGRAM_HH

#include <QWidget>
#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QCategoryAxis>

namespace Ui {
class OknoDialog;

}
class OknoDiagram : public QDialog
{
    Q_OBJECT

public:
    explicit OknoDiagram(QWidget *parent = nullptr);
    ~OknoDiagram();
     void wykres(double temp[],QDateTime data[]);

private:
    Ui::OknoDialog *ui; // Dodaj wskaźnik na obiekt interfejsu użytkownika
    QGraphicsView *m_graphicsView;
    QGraphicsScene *m_graphicsScene;
    QChartView *m_chartView;
    QChart *m_chart;
    QLineSeries *m_series;
private slots:

};

#endif // OKNODIAGRAM_H
