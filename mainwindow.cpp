#include "mainwindow.hh"
#include "ui_mainwindow.h"
/*!
* \file
* \brief Definicja metody klasy MainWindow
*
* Zawiera definicję metod klasy MainWindow
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*obiekty klasy QUrl zawierajace adresy Url służace do pobierania danych ze strony api.open_meteo*/
//    QUrl textUrl_wroc("https://api.open-meteo.com/v1/forecast?latitude=51.10&longitude=17.03&daily=weathercode,temperature_2m_max,sunrise,sunset,precipitation_sum,precipitation_probability_max,windspeed_10m_max,winddirection_10m_dominant,shortwave_radiation_sum,et0_fao_evapotranspiration&current_weather=true&timezone=auto");
//   QUrl textUrl_war("https://api.open-meteo.com/v1/forecast?latitude=52.23&longitude=21.01&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,rain_sum,snowfall_sum,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
//    QUrl textUrl_poz("https://api.open-meteo.com/v1/forecast?latitude=52.41&longitude=16.93&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,rain_sum,snowfall_sum,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
//    QUrl textUrl_krk("https://api.open-meteo.com/v1/forecast?latitude=50.06&longitude=19.94&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,rain_sum,snowfall_sum,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
//    QUrl textUrl_lodz("https://api.open-meteo.com/v1/forecast?latitude=51.77&longitude=19.47&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,rain_sum,snowfall_sum,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_wroc("https://api.open-meteo.com/v1/forecast?latitude=51.10&longitude=17.03&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_war("https://api.open-meteo.com/v1/forecast?latitude=52.23&longitude=21.01&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_poz("https://api.open-meteo.com/v1/forecast?latitude=52.41&longitude=16.93&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_krk("https://api.open-meteo.com/v1/forecast?latitude=50.06&longitude=19.94&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_lodz("https://api.open-meteo.com/v1/forecast?latitude=51.77&longitude=19.47&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
   /*obiekty klasy FileDownloader*/
    //oknoDiagram = new OknoDiagram(this);
    m_pTextCtrl_wroc = new FileDownloader(textUrl_wroc, this);
    m_pTextCtrl_war = new FileDownloader(textUrl_war, this);
    m_pTextCtrl_poz = new FileDownloader(textUrl_poz, this);
    m_pTextCtrl_krk = new FileDownloader(textUrl_krk, this);
    m_pTextCtrl_lodz = new FileDownloader(textUrl_lodz, this);
    //Temperatura[7];
/*po zakończeniu pobierania są wywoływane odpowiednie sloty*/
    connect(m_pTextCtrl_wroc, SIGNAL (downloaded()), this, SLOT (loadText_wroc()));
    connect(m_pTextCtrl_war, SIGNAL (downloaded()), this, SLOT (loadText_war()));
    connect(m_pTextCtrl_poz, SIGNAL (downloaded()), this, SLOT (loadText_poz()));
    connect(m_pTextCtrl_krk, SIGNAL (downloaded()), this, SLOT (loadText_krk()));
    connect(m_pTextCtrl_lodz, SIGNAL (downloaded()), this, SLOT (loadText_lodz()));
    connect(m_pTextCtrl_war, SIGNAL (downloaded()), this, SLOT (load_weather_war()));


}

/*!
 * \brief Metoda wywolujaca odpowiedni slot
* w zależności od wyboru miasta powoduje pobranie odpowiednich danych i wywoła odpowiedni slot odpowiedialny za wyswietlanie prognozy pogody dla danego miasta
 * \param index index miasta
 */

void MainWindow::onCitySelected(int index)
{

//OknoDiagram *Diagram = new OknoDiagram(this);
    QUrl textUrl_wroc("https://api.open-meteo.com/v1/forecast?latitude=51.10&longitude=17.03&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_war("https://api.open-meteo.com/v1/forecast?latitude=52.23&longitude=21.01&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_poz("https://api.open-meteo.com/v1/forecast?latitude=52.41&longitude=16.93&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_krk("https://api.open-meteo.com/v1/forecast?latitude=50.06&longitude=19.94&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_lodz("https://api.open-meteo.com/v1/forecast?latitude=51.77&longitude=19.47&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
   m_pTextCtrl_wroc = new FileDownloader(textUrl_wroc, this);
   m_pTextCtrl_war = new FileDownloader(textUrl_war, this);
   m_pTextCtrl_poz = new FileDownloader(textUrl_poz, this);
   m_pTextCtrl_krk = new FileDownloader(textUrl_krk, this);
   m_pTextCtrl_lodz = new FileDownloader(textUrl_lodz, this);

    switch(index) {
    case 0:
        connect(m_pTextCtrl_war, SIGNAL(downloaded()), this, SLOT(load_weather_war()));
        break;
    case 1:
        connect(m_pTextCtrl_krk, SIGNAL(downloaded()), this, SLOT(load_weather_krk()));
        break;
    case 2:
        connect(m_pTextCtrl_wroc, SIGNAL(downloaded()), this, SLOT(load_weather_wroc()));
        break;
    case 3:
       connect(m_pTextCtrl_poz, SIGNAL(downloaded()), this, SLOT(load_weather_poz()));
        //connect(m_pTextCtrl_wroc, SIGNAL(downloaded()), this, SLOT(load_weather_wroc()));
        //break;
        break;
    case 4:
        connect(m_pTextCtrl_lodz, SIGNAL(downloaded()), this, SLOT(load_weather_lodz()));
        break;
    default:
        break;
    }
    //Diagram->wykres(Temperatura);
}

/*!
 * \brief Funkcja zwracajaca kierunek wiatru
* zwraca skrót oznaczajacy kierunek wietru w zalezności od kierunku podanego w katach
 * \param degrees kąt kierunku wiatru
*/

QString direction(double degrees)
{
    QStringList directions = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};

    int index = qRound(degrees / 45.0) % 8;
    return directions[index];
}

/*!
 * \brief Funkcja zwracajaca kierunek geograficzny
* zwraca nazwe warunkow atmoserycznych w zaleznosci od kodu pogody
 * \param code kod określający pogodę
*/

int weather_conditions(double code)
{
    int index;
    //QStringList condition = {"slonce", "chmury", "deszcz", "śnieg", "mgła"};
         if(code==0){
        index=0;
    }
         else if (code>=1&& code<=3)
        index=1;
    else if(code==45||code==48)
        index=4;
    else if((code>=51&&code<=67)||(code>=80 && code<=82))
        index=2;
    else if((code>=71 && code<=77)||(code>=85 && code<=86))
        index=3;
    else if(code>=95 && code<=99)
        index=5;
    return index;
}
MainWindow::~MainWindow()
{
    delete ui;
    delete m_pTextCtrl_wroc;
    delete m_pTextCtrl_war;
    delete m_pTextCtrl_poz;
    delete m_pTextCtrl_krk;
    delete m_pTextCtrl_lodz;
    delete m_pTextCtrl_lodz;
    //delete Diagram;
}

/*!
 * \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace prognozy pogody dla Wrocławia
*/

void MainWindow::load_weather_wroc()
{   double temp1[7],wind1v[7],wind1d[7],weather1[7],UV_data[7];
    int index[7];
    double szerokosc = 100;
    double wysokosc;
    QString temp1Str[7],windvStr[7],winddStr[7],weatherStr[7],dateStr[7];
   QLabel* nazwa[7] = { ui->label_d1, ui->label_d2, ui->label_d3, ui->label_d4, ui->label_d5, ui->label_d6, ui->label_d7 };
    QLabel* UV[7] = { ui->Uv,  ui->Uv_2,  ui->Uv_3,  ui->Uv_4,  ui->Uv_5, ui->Uv_6, ui->Uv_7 };
    QLabel* predkosc[7] = { ui->predkosc, ui->predkosc_2, ui->predkosc_3, ui->predkosc_4, ui->predkosc_5,ui->predkosc_6, ui->predkosc_7 };
    QLabel* kierunek[7] = { ui->kierunek_1,  ui->kierunek_2,  ui->kierunek_3,  ui->kierunek_4,  ui->kierunek_5,  ui->kierunek_6,  ui->kierunek_7 };
   QLabel* pogoda[7] = { ui->pogoda_1,  ui->pogoda_2,  ui->pogoda_3,  ui->pogoda_4,  ui->pogoda_5,  ui->pogoda_6,  ui->pogoda_7 };
    QLabel* temperatura[7] = { ui->temp1,  ui->temp1_2,  ui->temp1_3,  ui->temp1_4,  ui->temp1_5,  ui->temp1_6,  ui->temp1_7 };
   QLabel* slupek[7] = { ui->slupek,  ui->slupek_2,  ui->slupek_3,  ui->slupek_4, ui->slupek_5,  ui->slupek_6,  ui->slupek_7 };
   QPixmap pixmap(":/img/rysunek.svg");
    QPixmap pixmapArray[6];

    // Dodawanie odnośników do obrazów
    pixmapArray[0] = QPixmap(":/img/slonce.svg");
    pixmapArray[1] = QPixmap(":/img/chmurka.svg");
    pixmapArray[2] = QPixmap(":/img/deszcz.svg");
pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
pixmapArray[4] = QPixmap(":/img/mgla.svg");
pixmapArray[5] = QPixmap(":/img/burza.svg");


    QTransform transform;
    QLocale locale("pl_PL");
    QDateTime dateTime[7];
    QString formattedDate[7];
    //konwersja danych i weodrebnienie obiektu QJsonObject
    QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_wroc->downloadedData());
    QJsonObject jsonObj = jsonDoc.object();
    //odczytywanie  danych z pola daily i konwertowanie danych by byly w formie tablic
    QJsonArray temp = jsonObj["daily"].toObject()["temperature_2m_max"].toArray();
    QJsonArray windv = jsonObj["daily"].toObject()["windspeed_10m_max"].toArray();
    QJsonArray windd = jsonObj["daily"].toObject()["winddirection_10m_dominant"].toArray();
    QJsonArray weather = jsonObj["daily"].toObject()["weathercode"].toArray();
    QJsonArray UV_S = jsonObj["daily"].toObject()["uv_index_max"].toArray();
     QJsonArray date = jsonObj["daily"].toObject()["time"].toArray();
    /*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
    for (int i = 0; i < 7; ++i) {
        temp1[i] = temp[i].toDouble();
        Temperatura[i]=temp1[i];
        wind1v[i] = windv[i].toDouble();
        wind1d[i] = windd[i].toDouble();
        weather1[i] = weather[i].toDouble();
        dateStr[i]=date[i].toString();
        UV_data[i]=UV_S[i].toDouble();
        wysokosc=temp1[i]*3;
        QPixmap slupek_temp(szerokosc, wysokosc);
        if(temp1[i]>=30)
            slupek_temp.fill(Qt::red);
        if(temp1[i]>=20 && temp1[i]<30)
            slupek_temp.fill(QColorConstants::Svg::orange);
        if(temp1[i]>=10 && temp1[i]<20)
            slupek_temp.fill(Qt::yellow);
        if(temp1[i]>=0 && temp1[i]<10)
            slupek_temp.fill(Qt::green);
        dateTime[i] = QDateTime::fromString(dateStr[i], Qt::ISODate);
        Data_wykres[i]=dateTime[i];
        transform.rotate(wind1d[i]);
        QPixmap rotatedPixmap = pixmap.transformed(transform, Qt::SmoothTransformation);


        formattedDate[i] = dateTime[i].toString("dd.MM\n") + locale.dayName(dateTime[i].date().dayOfWeek(), QLocale::ShortFormat);
        temp1Str[i] = QString::number(temp1[i], 'f', 0);
        windvStr[i] = QString::number(wind1v[i], 'f', 0);
        //winddStr[i] = direction(wind1d[i]);
        index[i] = weather_conditions(weather1[i]);
        pogoda[i]->setPixmap(pixmapArray[index[i]]);
        //pogoda[i]->setPixmap(pixmapArray[5]);

        kierunek[i]->setPixmap(rotatedPixmap);
        slupek[i]->setPixmap(slupek_temp);

        nazwa[i]->setText(tr("%1").arg(formattedDate[i]));
        predkosc[i]->setText(tr(" %1 \n km/h").arg(QStringView(windvStr[i])));
        temperatura[i]->setText(tr("%1 \u2103").arg(temp1Str[i]));
        //qDebug()<<UV_S[i];
        UV[i]->setText(tr("%1").arg(UV_data[i]));
        //nazwa[i]->setText(tr("%1 \u2103 \n %2  \n %3 \n %4 \n km/h").arg(temp1Str[i]).arg(QStringView(weatherStr[i])).arg(formattedDate[i]).arg(QStringView(windvStr[i])));
    }

    //m_pTextCtrl_wroc->clear();
}
/*!
 * \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace prognozy pogody dla Warszawy
*
*/

void MainWindow::load_weather_war()
{   double temp1[7],wind1v[7],wind1d[7],weather1[7],UV_data[7];
    int index[7];
    double szerokosc = 100;
    double wysokosc;
    QString temp1Str[7],windvStr[7],winddStr[7],weatherStr[7],dateStr[7];
    QLabel* nazwa[7] = { ui->label_d1, ui->label_d2, ui->label_d3, ui->label_d4, ui->label_d5, ui->label_d6, ui->label_d7 };
    QLabel* UV[7] = { ui->Uv,  ui->Uv_2,  ui->Uv_3,  ui->Uv_4,  ui->Uv_5, ui->Uv_6, ui->Uv_7 };
    QLabel* predkosc[7] = { ui->predkosc, ui->predkosc_2, ui->predkosc_3, ui->predkosc_4, ui->predkosc_5,ui->predkosc_6, ui->predkosc_7 };
    QLabel* kierunek[7] = { ui->kierunek_1,  ui->kierunek_2,  ui->kierunek_3,  ui->kierunek_4,  ui->kierunek_5,  ui->kierunek_6,  ui->kierunek_7 };
    QPixmap pixmap(":/img/rysunek.svg");
    QLabel* pogoda[7] = { ui->pogoda_1,  ui->pogoda_2,  ui->pogoda_3,  ui->pogoda_4,  ui->pogoda_5,  ui->pogoda_6,  ui->pogoda_7 };
    QLabel* temperatura[7] = { ui->temp1,  ui->temp1_2,  ui->temp1_3,  ui->temp1_4,  ui->temp1_5,  ui->temp1_6,  ui->temp1_7 };
    QLabel* slupek[7] = { ui->slupek,  ui->slupek_2,  ui->slupek_3,  ui->slupek_4, ui->slupek_5,  ui->slupek_6,  ui->slupek_7 };
    QPixmap pixmapArray[6];

    // Dodawanie odnośników do obrazów
    pixmapArray[0] = QPixmap(":/img/slonce.svg");
    pixmapArray[1] = QPixmap(":/img/chmurka.svg");
    pixmapArray[2] = QPixmap(":/img/deszcz.svg");
    pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
    pixmapArray[4] = QPixmap(":/img/mgla.svg");
    pixmapArray[5] = QPixmap(":/img/burza.svg");


    QTransform transform;
    QLocale locale("pl_PL");
    QDateTime dateTime[7];
    QString formattedDate[7];
     //konwersja danych i weodrebnienie obiektu QJsonObject
    QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_war->downloadedData());
    QJsonObject jsonObj = jsonDoc.object();
     //odczytywanie  danych z pola daily i konwertowanie danych by byly w formie tablic
    QJsonArray temp = jsonObj["daily"].toObject()["temperature_2m_max"].toArray();
    QJsonArray windv = jsonObj["daily"].toObject()["windspeed_10m_max"].toArray();
    QJsonArray windd = jsonObj["daily"].toObject()["winddirection_10m_dominant"].toArray();
    QJsonArray UV_S = jsonObj["daily"].toObject()["uv_index_max"].toArray();
    QJsonArray weather = jsonObj["daily"].toObject()["weathercode"].toArray();
    QJsonArray date = jsonObj["daily"].toObject()["time"].toArray();
     /*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
    for (int i = 0; i < 7; ++i) {
        temp1[i] = temp[i].toDouble();
        Temperatura[i]=temp1[i];
        wind1v[i] = windv[i].toDouble();
        wind1d[i] = windd[i].toDouble();
        weather1[i] = weather[i].toDouble();
        dateStr[i]=date[i].toString();
        UV_data[i]=UV_S[i].toDouble();
        wysokosc=temp1[i]*3;
        QPixmap slupek_temp(szerokosc, wysokosc);
        if(temp1[i]>=30)
            slupek_temp.fill(Qt::red);
        if(temp1[i]>=20 && temp1[i]<30)
            slupek_temp.fill(QColorConstants::Svg::orange);
        if(temp1[i]>=10 && temp1[i]<20)
            slupek_temp.fill(Qt::yellow);
        if(temp1[i]>=0 && temp1[i]<10)
            slupek_temp.fill(Qt::green);
        dateTime[i] = QDateTime::fromString(dateStr[i], Qt::ISODate);
        Data_wykres[i]=dateTime[i];
        transform.rotate(wind1d[i]);
        QPixmap rotatedPixmap = pixmap.transformed(transform, Qt::SmoothTransformation);

       formattedDate[i] = dateTime[i].toString("dd.MM\n") + locale.dayName(dateTime[i].date().dayOfWeek(), QLocale::ShortFormat);


        temp1Str[i] = QString::number(temp1[i], 'f', 0);
        windvStr[i] = QString::number(wind1v[i], 'f', 0);

        index[i] = weather_conditions(weather1[i]);
        //index[i]=2;
        pogoda[i]->setPixmap(pixmapArray[index[i]]);
        //pogoda[i]->setText(tr("%1").arg(index[i]));
        kierunek[i]->setPixmap(rotatedPixmap);
        slupek[i]->setPixmap(slupek_temp);
        nazwa[i]->setText(tr("%1").arg(formattedDate[i]));
        predkosc[i]->setText(tr(" %1 \n km/h").arg(QStringView(windvStr[i])));
        temperatura[i]->setText(tr("%1 \u2103").arg(temp1Str[i]));
        UV[i]->setText(tr("%1").arg(UV_data[i]));
        //nazwa[i]->setText(tr("%1 \u2103 \n %2  \n %3 \n %4 \n km/h").arg(temp1Str[i]).arg(QStringView(weatherStr[i])).arg(formattedDate[i]).arg(QStringView(windvStr[i])));
       // nazwa[i]->setText(tr("%1 \u2103 \n %2 \n km/h \n %3 \n %4 \n %5").arg(temp1Str[i]).arg(QStringView(windvStr[i])).arg(QStringView(winddStr[i])).arg(QStringView(weatherStr[i])).arg(formattedDate[i]));
    }

    //m_pTextCtrl_wroc->clear();
}
/*!
 * \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace prognozy pogody dla Poznania
*
*/
void MainWindow::load_weather_poz()
{   double temp1[7],wind1v[7],wind1d[7],weather1[7],UV_data[7];
    int index[7];
    double szerokosc = 100;
    double wysokosc;
    QString temp1Str[7],windvStr[7],winddStr[7],weatherStr[7],dateStr[7];
    QLabel* nazwa[7] = { ui->label_d1, ui->label_d2, ui->label_d3, ui->label_d4, ui->label_d5, ui->label_d6, ui->label_d7 };
    QLabel* predkosc[7] = { ui->predkosc, ui->predkosc_2, ui->predkosc_3, ui->predkosc_4, ui->predkosc_5,ui->predkosc_6, ui->predkosc_7 };
    QLabel* UV[7] = { ui->Uv,  ui->Uv_2,  ui->Uv_3,  ui->Uv_4,  ui->Uv_5, ui->Uv_6, ui->Uv_7 };
    QLabel* kierunek[7] = { ui->kierunek_1,  ui->kierunek_2,  ui->kierunek_3,  ui->kierunek_4,  ui->kierunek_5,  ui->kierunek_6,  ui->kierunek_7 };
    QPixmap pixmap(":/img/rysunek.svg");
    QLabel* pogoda[7] = { ui->pogoda_1,  ui->pogoda_2,  ui->pogoda_3,  ui->pogoda_4,  ui->pogoda_5,  ui->pogoda_6,  ui->pogoda_7 };
    QLabel* temperatura[7] = { ui->temp1,  ui->temp1_2,  ui->temp1_3,  ui->temp1_4,  ui->temp1_5,  ui->temp1_6,  ui->temp1_7 };
    QLabel* slupek[7] = { ui->slupek,  ui->slupek_2,  ui->slupek_3,  ui->slupek_4, ui->slupek_5,  ui->slupek_6,  ui->slupek_7 };
    QPixmap pixmapArray[6];

    // Dodawanie odnośników do obrazów
    pixmapArray[0] = QPixmap(":/img/slonce.svg");
    pixmapArray[1] = QPixmap(":/img/chmurka.svg");
    pixmapArray[2] = QPixmap(":/img/deszcz.svg");
    pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
    pixmapArray[4] = QPixmap(":/img/mgla.svg");
    pixmapArray[5] = QPixmap(":/img/burza.svg");


    QTransform transform;
    QLocale locale("pl_PL");
    QDateTime dateTime[7];
    QString formattedDate[7];
        //konwersja danych i weodrebnienie obiektu QJsonObject
    QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_poz->downloadedData());
    QJsonObject jsonObj = jsonDoc.object();
        //odczytywanie  danych z pola daily i konwertowanie danych by byly w formie tablic
    QJsonArray temp = jsonObj["daily"].toObject()["temperature_2m_max"].toArray();
    QJsonArray windv = jsonObj["daily"].toObject()["windspeed_10m_max"].toArray();
    QJsonArray UV_S = jsonObj["daily"].toObject()["uv_index_max"].toArray();
    QJsonArray windd = jsonObj["daily"].toObject()["winddirection_10m_dominant"].toArray();
    QJsonArray weather = jsonObj["daily"].toObject()["weathercode"].toArray();
    QJsonArray date = jsonObj["daily"].toObject()["time"].toArray();
    /*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
    for (int i = 0; i < 7; ++i) {
        temp1[i] = temp[i].toDouble();
        Temperatura[i]=temp1[i];
        wind1v[i] = windv[i].toDouble();
        wind1d[i] = windd[i].toDouble();
        weather1[i] = weather[i].toDouble();
        dateStr[i]=date[i].toString();
        UV_data[i]=UV_S[i].toDouble();
        wysokosc=temp1[i]*3;
        QPixmap slupek_temp(szerokosc, wysokosc);
        if(temp1[i]>=30)
            slupek_temp.fill(Qt::red);
        if(temp1[i]>=20 && temp1[i]<30)
            slupek_temp.fill(QColorConstants::Svg::orange);
        if(temp1[i]>=10 && temp1[i]<20)
            slupek_temp.fill(Qt::yellow);
        if(temp1[i]>=0 && temp1[i]<10)
            slupek_temp.fill(Qt::green);
        dateTime[i] = QDateTime::fromString(dateStr[i], Qt::ISODate);
         Data_wykres[i]=dateTime[i];
        transform.rotate(wind1d[i]);
        QPixmap rotatedPixmap = pixmap.transformed(transform, Qt::SmoothTransformation);

        formattedDate[i] = dateTime[i].toString("dd.MM\n") + locale.dayName(dateTime[i].date().dayOfWeek(), QLocale::ShortFormat);


        temp1Str[i] = QString::number(temp1[i], 'f', 0);
        windvStr[i] = QString::number(wind1v[i], 'f', 0);

        index[i] = weather_conditions(weather1[i]);
        pogoda[i]->setPixmap(pixmapArray[index[i]]);
        //pogoda[i]->setPixmap(pixmapArray[3]);

        kierunek[i]->setPixmap(rotatedPixmap);
        slupek[i]->setPixmap(slupek_temp);
        nazwa[i]->setText(tr("%1").arg(formattedDate[i]));
        predkosc[i]->setText(tr(" %1 \n km/h").arg(QStringView(windvStr[i])));
        temperatura[i]->setText(tr("%1 \u2103").arg(temp1Str[i]));
        UV[i]->setText(tr("%1").arg(UV_data[i]));
        //nazwa[i]->setText(tr("%1 \u2103 \n %2  \n %3 \n %4 \n km/h").arg(temp1Str[i]).arg(QStringView(weatherStr[i])).arg(formattedDate[i]).arg(QStringView(windvStr[i])));
        // nazwa[i]->setText(tr("%1 \u2103 \n %2 \n km/h \n %3 \n %4 \n %5").arg(temp1Str[i]).arg(QStringView(windvStr[i])).arg(QStringView(winddStr[i])).arg(QStringView(weatherStr[i])).arg(formattedDate[i]));
    }

    //m_pTextCtrl_wroc->clear();
}

/*!
 * \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace prognozy pogody dla Krakowa
*
*/
void MainWindow::load_weather_krk()
{   double temp1[7],wind1v[7],wind1d[7],weather1[7],UV_data[7];
    int index[7];
    double szerokosc = 100;
    double wysokosc;
    QString temp1Str[7],windvStr[7],winddStr[7],weatherStr[7],dateStr[7];
    QLabel* nazwa[7] = { ui->label_d1, ui->label_d2, ui->label_d3, ui->label_d4, ui->label_d5, ui->label_d6, ui->label_d7 };
    QLabel* UV[7] = { ui->Uv,  ui->Uv_2,  ui->Uv_3,  ui->Uv_4,  ui->Uv_5, ui->Uv_6, ui->Uv_7 };
    QLabel* predkosc[7] = { ui->predkosc, ui->predkosc_2, ui->predkosc_3, ui->predkosc_4, ui->predkosc_5,ui->predkosc_6, ui->predkosc_7 };

    QLabel* kierunek[7] = { ui->kierunek_1,  ui->kierunek_2,  ui->kierunek_3,  ui->kierunek_4,  ui->kierunek_5,  ui->kierunek_6,  ui->kierunek_7 };
    QPixmap pixmap(":/img/rysunek.svg");
    QLabel* pogoda[7] = { ui->pogoda_1,  ui->pogoda_2,  ui->pogoda_3,  ui->pogoda_4,  ui->pogoda_5,  ui->pogoda_6,  ui->pogoda_7 };
    QLabel* temperatura[7] = { ui->temp1,  ui->temp1_2,  ui->temp1_3,  ui->temp1_4,  ui->temp1_5,  ui->temp1_6,  ui->temp1_7 };
    QLabel* slupek[7] = { ui->slupek,  ui->slupek_2,  ui->slupek_3,  ui->slupek_4, ui->slupek_5,  ui->slupek_6,  ui->slupek_7 };
    QPixmap pixmapArray[6];

    // Dodawanie odnośników do obrazów
    pixmapArray[0] = QPixmap(":/img/slonce.svg");
    pixmapArray[1] = QPixmap(":/img/chmurka.svg");
    pixmapArray[2] = QPixmap(":/img/deszcz.svg");
    pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
    pixmapArray[4] = QPixmap(":/img/mgla.svg");
    pixmapArray[5] = QPixmap(":/img/burza.svg");

    QTransform transform;
    QLocale locale("pl_PL");
    QDateTime dateTime[7];
    QString formattedDate[7];
     //konwersja danych i weodrebnienie obiektu QJsonObject
    QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_krk->downloadedData());
    QJsonObject jsonObj = jsonDoc.object();
     //odczytywanie  danych z pola daily i konwertowanie danych by byly w formie tablic
    QJsonArray temp = jsonObj["daily"].toObject()["temperature_2m_max"].toArray();
    QJsonArray windv = jsonObj["daily"].toObject()["windspeed_10m_max"].toArray();
    QJsonArray UV_S = jsonObj["daily"].toObject()["uv_index_max"].toArray();
    QJsonArray windd = jsonObj["daily"].toObject()["winddirection_10m_dominant"].toArray();
    QJsonArray weather = jsonObj["daily"].toObject()["weathercode"].toArray();
     QJsonArray date = jsonObj["daily"].toObject()["time"].toArray();
     /*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
    for (int i = 0; i < 7; ++i) {
        temp1[i] = temp[i].toDouble();
        Temperatura[i]=temp1[i];
        wind1v[i] = windv[i].toDouble();
        wind1d[i] = windd[i].toDouble();
        weather1[i] = weather[i].toDouble();
        dateStr[i]=date[i].toString();
        UV_data[i]=UV_S[i].toDouble();
        wysokosc=temp1[i]*3;
        QPixmap slupek_temp(szerokosc, wysokosc);
        if(temp1[i]>=30)
            slupek_temp.fill(Qt::red);
        if(temp1[i]>=20 && temp1[i]<30)
            slupek_temp.fill(QColorConstants::Svg::orange);
        if(temp1[i]>=10 && temp1[i]<20)
            slupek_temp.fill(Qt::yellow);
        if(temp1[i]>=0 && temp1[i]<10)
            slupek_temp.fill(Qt::green);
        dateTime[i] = QDateTime::fromString(dateStr[i], Qt::ISODate);
         Data_wykres[i]=dateTime[i];
        transform.rotate(wind1d[i]);
        QPixmap rotatedPixmap = pixmap.transformed(transform, Qt::SmoothTransformation);
        formattedDate[i] = dateTime[i].toString("dd.MM\n") + locale.dayName(dateTime[i].date().dayOfWeek(), QLocale::ShortFormat);

        temp1Str[i] = QString::number(temp1[i], 'f', 0);
        windvStr[i] = QString::number(wind1v[i], 'f', 0);

        index[i] = weather_conditions(weather1[i]);
        pogoda[i]->setPixmap(pixmapArray[index[i]]);
        //pogoda[i]->setPixmap(pixmapArray[0]);

        kierunek[i]->setPixmap(rotatedPixmap);
        slupek[i]->setPixmap(slupek_temp);
        //nazwa[i]->setText(tr("%1 \u2103 \n %2  \n %3 \n %4 \n km/h").arg(temp1Str[i]).arg(QStringView(weatherStr[i])).arg(formattedDate[i]).arg(QStringView(windvStr[i])));
        nazwa[i]->setText(tr("%1").arg(formattedDate[i]));
        predkosc[i]->setText(tr(" %1 \n km/h").arg(QStringView(windvStr[i])));
        temperatura[i]->setText(tr("%1 \u2103").arg(temp1Str[i]));
        UV[i]->setText(tr("%1").arg(UV_data[i]));
        //nazwa[i]->setText(tr("%1 \u2103 \n %2 \n km/h \n %3 \n %4 \n %5").arg(temp1Str[i]).arg(QStringView(windvStr[i])).arg(QStringView(winddStr[i])).arg(QStringView(weatherStr[i])).arg(formattedDate[i]));
    }


}
/*!
 * \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace prognozy pogody dla Łodzi
*
*/
void MainWindow::load_weather_lodz()
{   double temp1[7],wind1v[7],wind1d[7],weather1[7],UV_data[7];
    int index[7];
    double szerokosc = 100;
    double wysokosc;
    QString temp1Str[7],windvStr[7],winddStr[7],weatherStr[7],dateStr[7];
    QLabel* nazwa[7] = { ui->label_d1, ui->label_d2, ui->label_d3, ui->label_d4, ui->label_d5, ui->label_d6, ui->label_d7 };
    QLabel* UV[7] = { ui->Uv,  ui->Uv_2,  ui->Uv_3,  ui->Uv_4,  ui->Uv_5, ui->Uv_6, ui->Uv_7 };
    QLabel* kierunek[7] = { ui->kierunek_1,  ui->kierunek_2,  ui->kierunek_3,  ui->kierunek_4,  ui->kierunek_5,  ui->kierunek_6,  ui->kierunek_7 };
    QLabel* predkosc[7] = { ui->predkosc, ui->predkosc_2, ui->predkosc_3, ui->predkosc_4, ui->predkosc_5,ui->predkosc_6, ui->predkosc_7 };
    QPixmap pixmap(":/img/rysunek.svg");
    QLabel* pogoda[7] = { ui->pogoda_1,  ui->pogoda_2,  ui->pogoda_3,  ui->pogoda_4,  ui->pogoda_5,  ui->pogoda_6,  ui->pogoda_7 };
    QLabel* temperatura[7] = { ui->temp1,  ui->temp1_2,  ui->temp1_3,  ui->temp1_4,  ui->temp1_5,  ui->temp1_6,  ui->temp1_7 };
    QLabel* slupek[7] = { ui->slupek,  ui->slupek_2,  ui->slupek_3,  ui->slupek_4, ui->slupek_5,  ui->slupek_6,  ui->slupek_7 };
   //QPixmap slupek_temp(initialWidth, initialHeight);

    QPixmap pixmapArray[6];

    // Dodawanie odnośników do obrazów
    pixmapArray[0] = QPixmap(":/img/slonce.svg");
    pixmapArray[1] = QPixmap(":/img/chmurka.svg");
    pixmapArray[2] = QPixmap(":/img/deszcz.svg");
    pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
    pixmapArray[4] = QPixmap(":/img/mgla.svg");
    pixmapArray[5] = QPixmap(":/img/burza.svg");

    QTransform transform;
    QLocale locale("pl_PL");
    QDateTime dateTime[7];
    QString formattedDate[7];
     //konwersja danych i weodrebnienie obiektu QJsonObject
    QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_lodz->downloadedData());
    QJsonObject jsonObj = jsonDoc.object();
     //odczytywanie  danych z pola daily i konwertowanie danych by byly w formie tablic
    QJsonArray temp = jsonObj["daily"].toObject()["temperature_2m_max"].toArray();
    QJsonArray windv = jsonObj["daily"].toObject()["windspeed_10m_max"].toArray();
    QJsonArray UV_S = jsonObj["daily"].toObject()["uv_index_max"].toArray();
    QJsonArray windd = jsonObj["daily"].toObject()["winddirection_10m_dominant"].toArray();
    QJsonArray weather = jsonObj["daily"].toObject()["weathercode"].toArray();
     QJsonArray date = jsonObj["daily"].toObject()["time"].toArray();

    //ui->slupek->setPixmap(slupek_temp);

     /*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
    for (int i = 0; i < 7; ++i) {
        temp1[i] = temp[i].toDouble();
        Temperatura[i]=temp1[i];
        wind1v[i] = windv[i].toDouble();
        wind1d[i] = windd[i].toDouble();
        weather1[i] = weather[i].toDouble();
        dateStr[i]=date[i].toString();
        UV_data[i]=UV_S[i].toDouble();
         wysokosc=temp1[i]*3;
        QPixmap slupek_temp(szerokosc, wysokosc);
        if(temp1[i]>=30)
            slupek_temp.fill(Qt::red);
        if(temp1[i]>=20 && temp1[i]<30)
            slupek_temp.fill(QColorConstants::Svg::orange);
        if(temp1[i]>=10 && temp1[i]<20)
            slupek_temp.fill(Qt::yellow);
        if(temp1[i]>=0 && temp1[i]<10)
            slupek_temp.fill(Qt::green);
        dateTime[i] = QDateTime::fromString(dateStr[i], Qt::ISODate);
         Data_wykres[i]=dateTime[i];
        transform.rotate(wind1d[i]);
        QPixmap rotatedPixmap = pixmap.transformed(transform, Qt::SmoothTransformation);
        formattedDate[i] = dateTime[i].toString("dd.MM\n") + locale.dayName(dateTime[i].date().dayOfWeek(), QLocale::ShortFormat);

        temp1Str[i] = QString::number(temp1[i], 'f', 0);
        windvStr[i] = QString::number(wind1v[i], 'f', 0);


        index[i] = weather_conditions(weather1[i]);
        pogoda[i]->setPixmap(pixmapArray[index[i]]);

        kierunek[i]->setPixmap(rotatedPixmap);
        slupek[i]->setPixmap(slupek_temp);
        //slupek[i]->move(0,80);
        nazwa[i]->setText(tr("%1").arg(formattedDate[i]));
        predkosc[i]->setText(tr(" %1 \n km/h").arg(QStringView(windvStr[i])));
        temperatura[i]->setText(tr("%1 \u2103").arg(temp1Str[i]));
        UV[i]->setText(tr("%1").arg(UV_data[i]));

    }


}
/*!
 * \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace temperatury i czasów schodu i zachodu słońca dla Wrocławia
*
*/

void MainWindow::loadText_wroc()
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_wroc->downloadedData());
    QJsonObject jsonObj = jsonDoc.object();
    //odczytywanie  danych z pola daily i pola current_weather i konwertowanie danych by byly w odpowiednim formacie
    QJsonArray daily = jsonObj["daily"].toObject()["sunrise"].toArray();
    QJsonArray daily_2 = jsonObj["daily"].toObject()["sunset"].toArray();
    QJsonObject current = jsonObj["current_weather"].toObject();
    QPixmap pixmapArray[6];

    // Dodawanie odnośników do obrazów
    pixmapArray[0] = QPixmap(":/img/slonce.svg");
    pixmapArray[1] = QPixmap(":/img/chmurka.svg");
    pixmapArray[2] = QPixmap(":/img/deszcz.svg");
    pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
    pixmapArray[4] = QPixmap(":/img/mgla.svg");
    pixmapArray[5] = QPixmap(":/img/burza.svg");

    double weather=current["weathercode"].toDouble();
    double temperature = current["temperature"].toDouble();
    /*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
    QString temperatureStr = QString::number(temperature, 'f', 0);
    QString  sunrise = daily[0].toString();
    QString  sunset = daily_2[0].toString();
    int index = weather_conditions(weather);
    QDateTime sunriseDateTime = QDateTime::fromString(sunrise, Qt::ISODate); // konwersja do QDateTime
    QDateTime sunsetDateTime = QDateTime::fromString(sunset, Qt::ISODate); // konwersja do QDateTime
    QString sunriseTime = sunriseDateTime.time().toString("hh:mm");
    QString sunsetTime = sunsetDateTime.time().toString("hh:mm");// pobranie samej godziny
   ui->wroc_pog->setPixmap(pixmapArray[index]);
    ui->wroc_temp->setText(tr("%1 \u2103").arg(temperatureStr));
    ui->label_wroc->setText(tr(" Wrocław\n %1   %2").arg(QStringView(sunriseTime)).arg(QStringView(sunsetTime)));

}
/*!
 * \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace temperatury i czasów schodu i zachodu słońca dla Warszawy
*
*/
void MainWindow::loadText_war()
{
      QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_war->downloadedData());
      QJsonObject jsonObj = jsonDoc.object();
      //odczytywanie  danych z pola daily i pola current_weather i konwertowanie danych by byly w odpowiednim formacie
QJsonArray daily = jsonObj["daily"].toObject()["sunrise"].toArray();
QJsonArray daily_2 = jsonObj["daily"].toObject()["sunset"].toArray();
QJsonObject current = jsonObj["current_weather"].toObject();
QPixmap pixmapArray[6];

// Dodawanie odnośników do obrazów
pixmapArray[0] = QPixmap(":/img/slonce.svg");
pixmapArray[1] = QPixmap(":/img/chmurka.svg");
pixmapArray[2] = QPixmap(":/img/deszcz.svg");
pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
pixmapArray[4] = QPixmap(":/img/mgla.svg");
pixmapArray[5] = QPixmap(":/img/burza.svg");

double weather=current["weathercode"].toDouble();
double temperature = current["temperature"].toDouble();
/*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
QString temperatureStr = QString::number(temperature, 'f', 0);
QString  sunrise = daily[0].toString();
QString  sunset = daily_2[0].toString();
int index = weather_conditions(weather);
QDateTime sunriseDateTime = QDateTime::fromString(sunrise, Qt::ISODate); // konwersja do QDateTime
QDateTime sunsetDateTime = QDateTime::fromString(sunset, Qt::ISODate); // konwersja do QDateTime
QString sunriseTime = sunriseDateTime.time().toString("hh:mm");
 QString sunsetTime = sunsetDateTime.time().toString("hh:mm");// pobranie samej godziny
ui->war_pog->setPixmap(pixmapArray[index]);
ui->war_temp->setText(tr("%1 \u2103").arg(temperatureStr));
ui->label_war->setText(tr(" Warszawa \n %1   %2").arg(QStringView(sunriseTime)).arg(QStringView(sunsetTime)));

}
/*!
* \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace temperatury i czasów schodu i zachodu słońca dla Poznania
*
*/
void MainWindow::loadText_poz()
{
 QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_poz->downloadedData());
 QJsonObject jsonObj = jsonDoc.object();

 //odczytywanie  danych z pola daily i pola current_weather i konwertowanie danych by byly w odpowiednim formacie
 QJsonArray daily = jsonObj["daily"].toObject()["sunrise"].toArray();
 QJsonArray daily_2 = jsonObj["daily"].toObject()["sunset"].toArray();
 QJsonObject current = jsonObj["current_weather"].toObject();
 QPixmap pixmapArray[6];

 // Dodawanie odnośników do obrazów
 pixmapArray[0] = QPixmap(":/img/slonce.svg");
 pixmapArray[1] = QPixmap(":/img/chmurka.svg");
 pixmapArray[2] = QPixmap(":/img/deszcz.svg");
 pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
 pixmapArray[4] = QPixmap(":/img/mgla.svg");
 pixmapArray[5] = QPixmap(":/img/burza.svg");

 double weather=current["weathercode"].toDouble();
 double temperature = current["temperature"].toDouble();
 /*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
 QString temperatureStr = QString::number(temperature, 'f', 0);
 QString  sunrise = daily[0].toString();
 QString  sunset = daily_2[0].toString();
 int index = weather_conditions(weather);
 QDateTime sunriseDateTime = QDateTime::fromString(sunrise, Qt::ISODate); // konwersja do QDateTime
 QDateTime sunsetDateTime = QDateTime::fromString(sunset, Qt::ISODate); // konwersja do QDateTime
 QString sunriseTime = sunriseDateTime.time().toString("hh:mm");
 QString sunsetTime = sunsetDateTime.time().toString("hh:mm");// pobranie samej godziny
 ui->poz_pog->setPixmap(pixmapArray[index]);
 ui->poz_temp->setText(tr("%1 \u2103").arg(temperatureStr));
 ui->label_poz->setText(tr(" Poznań \n %1   %2").arg(QStringView(sunriseTime)).arg(QStringView(sunsetTime)));
 //m_pTextCtrl_poz->deleteLater();
 //m_pTextCtrl_war->clear();
}
/*!
 * \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace temperatury i czasów schodu i zachodu słońca dla Krakowa
*
*/
void MainWindow::loadText_krk()
{
 QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_krk->downloadedData());
 QJsonObject jsonObj = jsonDoc.object();
 //odczytywanie  danych z pola daily i pola current_weather i konwertowanie danych by byly w odpowiednim formacie
 QJsonArray daily = jsonObj["daily"].toObject()["sunrise"].toArray();
 QJsonArray daily_2 = jsonObj["daily"].toObject()["sunset"].toArray();
 QJsonObject current = jsonObj["current_weather"].toObject();
 QPixmap pixmapArray[6];

 // Dodawanie odnośników do obrazów
 pixmapArray[0] = QPixmap(":/img/slonce.svg");
 pixmapArray[1] = QPixmap(":/img/chmurka.svg");
 pixmapArray[2] = QPixmap(":/img/deszcz.svg");
 pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
 pixmapArray[4] = QPixmap(":/img/mgla.svg");
 pixmapArray[5] = QPixmap(":/img/burza.svg");

 double weather=current["weathercode"].toDouble();
 double temperature = current["temperature"].toDouble();
 /*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
 QString temperatureStr = QString::number(temperature, 'f', 0);
 QString  sunrise = daily[0].toString();
 QString  sunset = daily_2[0].toString();
 int index = weather_conditions(weather);
 QDateTime sunriseDateTime = QDateTime::fromString(sunrise, Qt::ISODate); // konwersja do QDateTime
 QDateTime sunsetDateTime = QDateTime::fromString(sunset, Qt::ISODate); // konwersja do QDateTime
 QString sunriseTime = sunriseDateTime.time().toString("hh:mm");
 QString sunsetTime = sunsetDateTime.time().toString("hh:mm");// pobranie samej godziny
 ui->krk_pog->setPixmap(pixmapArray[index]);
 ui->krk_temp->setText(tr("%1 \u2103").arg(temperatureStr));
 ui->label_krk->setText(tr(" Kraków \n %1   %2").arg(QStringView(sunriseTime)).arg(QStringView(sunsetTime)));
 //m_pTextCtrl_krk->deleteLater();
     // m_pTextCtrl_krk->clear();
}
/*!
 * \brief Metoda odczytuje,przetwarza i wyświetla dane dotycznace temperatury i czasów schodu i zachodu słońca dla Łodzi
*
*/
void MainWindow::loadText_lodz()
{
      QJsonDocument jsonDoc = QJsonDocument::fromJson(m_pTextCtrl_lodz->downloadedData());
      QJsonObject jsonObj = jsonDoc.object();
      //odczytywanie  danych z pola daily i pola current_weather i konwertowanie danych by byly w odpowiednim formacie
      QJsonArray daily = jsonObj["daily"].toObject()["sunrise"].toArray();
      QJsonArray daily_2 = jsonObj["daily"].toObject()["sunset"].toArray();
      QJsonObject current = jsonObj["current_weather"].toObject();
      QPixmap pixmapArray[6];

      // Dodawanie odnośników do obrazów
      pixmapArray[0] = QPixmap(":/img/slonce.svg");
      pixmapArray[1] = QPixmap(":/img/chmurka.svg");
      pixmapArray[2] = QPixmap(":/img/deszcz.svg");
      pixmapArray[3] = QPixmap(":/img/sniezynka.svg");
      pixmapArray[4] = QPixmap(":/img/mgla.svg");
      pixmapArray[5] = QPixmap(":/img/burza.svg");

      double weather=current["weathercode"].toDouble();
      double temperature = current["temperature"].toDouble();
      /*konwersja danych na obiekty QString i przetwarzanie na odpowiedni format*/
      QString temperatureStr = QString::number(temperature, 'f', 0);
      QString  sunrise = daily[0].toString();
      QString  sunset = daily_2[0].toString();
      int index = weather_conditions(weather);
      QDateTime sunriseDateTime = QDateTime::fromString(sunrise, Qt::ISODate); // konwersja do QDateTime
      QDateTime sunsetDateTime = QDateTime::fromString(sunset, Qt::ISODate); // konwersja do QDateTime
      QString sunriseTime = sunriseDateTime.time().toString("hh:mm");
      QString sunsetTime = sunsetDateTime.time().toString("hh:mm");// pobranie samej godziny
      ui->lodz_pog->setPixmap(pixmapArray[index]);
      ui->lodz_temp->setText(tr("%1 \u2103").arg(temperatureStr));
      ui->label_lodz->setText(tr(" Łódź \n %1   %2").arg(QStringView(sunriseTime)).arg(QStringView(sunsetTime)));

}
/*!
* \brief Slot reaguje na naciśniecię przycisku "odśwież"
*powoduje ponowne pobranie danych dotyczacych obecnej temeratury i czasu wschodu i zachodu slońca oraz wywoluje odpowiednie sloty odpowoedzialne z odzcyt przetwarzanie i wyswietlanie tych danych
*/
void MainWindow::ReloadButton()
{
    m_pTextCtrl_wroc->deleteLater();
    m_pTextCtrl_war->deleteLater();
    m_pTextCtrl_poz->deleteLater();
    m_pTextCtrl_krk->deleteLater();
    m_pTextCtrl_lodz->deleteLater();
    QUrl textUrl_wroc("https://api.open-meteo.com/v1/forecast?latitude=51.10&longitude=17.03&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_war("https://api.open-meteo.com/v1/forecast?latitude=52.23&longitude=21.01&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_poz("https://api.open-meteo.com/v1/forecast?latitude=52.41&longitude=16.93&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_krk("https://api.open-meteo.com/v1/forecast?latitude=50.06&longitude=19.94&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    QUrl textUrl_lodz("https://api.open-meteo.com/v1/forecast?latitude=51.77&longitude=19.47&daily=weathercode,temperature_2m_max,sunrise,sunset,uv_index_max,windspeed_10m_max,winddirection_10m_dominant&current_weather=true&timezone=auto");
    m_pTextCtrl_wroc = new FileDownloader(textUrl_wroc, this);
    m_pTextCtrl_war = new FileDownloader(textUrl_war, this);
    m_pTextCtrl_poz = new FileDownloader(textUrl_poz, this);
    m_pTextCtrl_krk = new FileDownloader(textUrl_krk, this);
    m_pTextCtrl_lodz = new FileDownloader(textUrl_lodz, this);
        connect(m_pTextCtrl_wroc, SIGNAL (downloaded()), this, SLOT (loadText_wroc()));
    connect(m_pTextCtrl_war, SIGNAL (downloaded()), this, SLOT (loadText_war()));
    connect(m_pTextCtrl_poz, SIGNAL (downloaded()), this, SLOT (loadText_poz()));
    connect(m_pTextCtrl_krk, SIGNAL (downloaded()), this, SLOT (loadText_krk()));
    connect(m_pTextCtrl_lodz, SIGNAL (downloaded()), this, SLOT (loadText_lodz()));


}
void MainWindow::diagram_clicked()
{
    //delete Diagram;
    //oknoDiagram = new OknoDiagram(this);
    OknoDiagram *Diagram = new OknoDiagram(this);// Tworzenie instancji nowego okna
    Diagram->wykres(Temperatura,Data_wykres);
    Diagram->show(); // Wyświetlanie nowego okna
   // Diagram->exec();
    //oknoDiagram->setVisible(true);
    //qDebug()<<Temperatura[0];
}
