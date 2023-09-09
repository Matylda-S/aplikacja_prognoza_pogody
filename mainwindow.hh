#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH
#include"filedownloader.hh"
#include"oknodiagram.hh"
#include "rapidjson/writer.h"
#include <QMainWindow>
#include<QLabel>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QRegularExpression>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
 //QRegularExpressionMatch  *match=nullptr;
    //QRegularExpression *regex=nullptr;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //OknoDiagram *oknoDiagram;
    FileDownloader *m_pTextCtrl_wroc;
    FileDownloader *m_pTextCtrl_war;
    FileDownloader *m_pTextCtrl_poz;
    FileDownloader *m_pTextCtrl_krk;
    FileDownloader *m_pTextCtrl_lodz;
    double Temperatura[7];
    QDateTime Data_wykres[7];
    QRegularExpression m_regex;
private slots:
    //void loadDate(QByteArray data);
   //void loadText(int num);
    //QString MainWindow::loadText(FileDownloader m_ptext,int num);
    void loadText_wroc();
    void load_weather_wroc();
    void loadText_war();
    void loadText_poz();
    void loadText_krk();
    void loadText_lodz();
    void load_weather_lodz();
    void load_weather_war();
    void load_weather_krk();
    void load_weather_poz();
    void ReloadButton();
    void onCitySelected(int index);
    void diagram_clicked();
};
#endif // MAINWINDOW_HH
