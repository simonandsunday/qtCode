#ifndef JSONTOHASH_H
#define JSONTOHASH_H
#include <QString>
#include<QVariantHash>
namespace Json {
class Value;
}
class JsonToHash
{
public:
    JsonToHash();
    ~JsonToHash();

public:
    QVariantHash AnalysisJSONToHash(const QString &jsonstr);
    QString AnalysisHashToJSON(const QVariantHash &hash);
private:
    QVariant m_AnalysisJSONToHash1(const Json::Value &value);
    Json::Value m_AnalysisHashToJSON(const QVariantHash &hash);
};

#endif // JSONTOHASH_H
