#ifndef FILEDOWNLOADER_HH
#define FILEDOWNLOADER_HH

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader(QUrl textUrl, QObject *parent = 0);
    virtual ~FileDownloader();
    QByteArray downloadedData() const;
    void clear();

signals:
    void downloaded();

private slots:
    void fileDownloaded(QNetworkReply* pReply);

private:
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
};

#endif // FILEDOWNLOADER_H
