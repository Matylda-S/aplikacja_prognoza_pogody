#include "filedownloader.hh"
/*!
* \file
* \brief Definicja metody klasy FileDownloader
*
* Zawiera definicję metod klasy FileDownloader
*/
/*!
 * \brief Metoda inicjalizujaca obiekt tej klasy
* w zależności od wyboru miasta powoduje pobranie odpowiednich danych i wywoła odpowiedni slot odpowiedialny za wyswietlanie prognozy pogody dla danego miasta
 * \param textUrl adres Url strony z której będą pobierane dane
 * \param parent rodzic
 */
FileDownloader::FileDownloader(QUrl textUrl, QObject *parent) :
    QObject(parent)
{

    connect(
        &m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
        this, SLOT (fileDownloaded(QNetworkReply*))
        );

    QNetworkRequest request(textUrl);
    m_WebCtrl.get(request);
}

FileDownloader::~FileDownloader() { }
/*! Odczytuje ona dane pobrane z QNetworkReply, czyści bufor i emituje sygnał downloaded()*/
void FileDownloader::fileDownloaded(QNetworkReply* pReply) {


    m_DownloadedData = pReply->readAll();
    pReply->deleteLater();
    emit downloaded();
}
/*!
 * \brief Metoda wraca pobrane dane
 * zwraca pobrane dane w formacie QByteArray
 */
QByteArray FileDownloader::downloadedData() const {
    return m_DownloadedData;
}
/*!
 * \brief Metoda czyści pobrane dane z bufora
 */
void FileDownloader::clear() {
    m_DownloadedData.clear();
}
