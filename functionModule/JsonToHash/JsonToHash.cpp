#include "JsonToHash.h"
#include "json/json.h"
#include<QByteArray>
#ifndef QStringLiteral
#define QStringLiteral QObject::tr
#endif
JsonToHash::JsonToHash()
{
}

JsonToHash::~JsonToHash()
{

}

QVariantHash JsonToHash::AnalysisJSONToHash(const QString &jsonStr)
{
    QByteArray jsonArray = jsonStr.toLocal8Bit();

    Json::Reader reader;
    Json::Value rootValue;

    if (reader.parse(jsonArray.constBegin(),
                     jsonArray.constEnd(),
                     rootValue))
    {
        return m_AnalysisJSONToHash1(rootValue).toHash();
    }
    return QVariantHash();
}

QString JsonToHash::AnalysisHashToJSON(const QVariantHash &hash)
{
    Json::StyledWriter writer;
    std::string content = writer.write(m_AnalysisHashToJSON(hash));
    QString retStr = QStringLiteral("%1").arg(content.data());

    return retStr;
}

QVariant JsonToHash::m_AnalysisJSONToHash1(const Json::Value &value)
{
    if (value.isObject())
    {
        //            typedef std::vector<std::string> Members;
        QVariantHash returnVar;
        Json::Value::Members members = value.getMemberNames();

        std::vector<std::string>::iterator iter = members.begin();
        while (iter != members.end()) {
            returnVar.insert(QString::fromStdString(*iter).toUpper(),
                             m_AnalysisJSONToHash1(value[*iter]));
            iter++;
        }
        return returnVar;
    }
    else if (value.isBool())
    {
        return value.asBool();
    }
    else if (value.isInt())
    {
        return value.asInt();
    }
    else if (value.isNull())
    {
        return QVariant();
    }
    else if (value.isArray())
    {
        QVariantList list;
        for (int i = 0; i < value.size(); ++i)
        {
            list.append(m_AnalysisJSONToHash1(value[i]));
        }
        return list;
    }
    else if (value.isDouble())
    {
        return value.asDouble();
    }
    else if (value.isString())
    {
        return QString::fromLocal8Bit(value.asCString());
    }

    return QVariant();
}

Json::Value JsonToHash::m_AnalysisHashToJSON(const QVariantHash &hash)
{
    Json::Value rootValue;

    QVariantHash::const_iterator iter;
    iter = hash.begin();
    while (iter != hash.end()) {
        if (iter.value().type() == QMetaType::QVariantHash)
        {
            rootValue[iter.key().toUtf8().data()] = m_AnalysisHashToJSON((*iter).toHash());
        }
        else if (iter.value().type() == QMetaType::QVariantList)
        {
            Json::Value value1;
            QVariantList::const_iterator iter1;
            QVariantList list((*iter).toList());
            iter1 = list.begin();
            while (iter1 != list.end()) {
                value1.append(m_AnalysisHashToJSON((*iter1).toHash()));
                iter1++;
            }
            rootValue[iter.key().toUtf8().data()] = value1;
        }
        else if (iter.value().type() == QVariant::Bool)
        {
            rootValue[iter.key().toUtf8().data()] = iter.value().toBool();
        }
        else if (iter.value().type() == QMetaType::QString)
        {
            rootValue[iter.key().toUtf8().data()] = iter.value().toString().toUtf8().data();
        }
        else if (iter.value().type() == QVariant::Int)
        {
            rootValue[iter.key().toUtf8().data()] = iter.value().toInt();
        }
        else if (iter.value().type() == QMetaType::Void)
        {
            rootValue[iter.key().toUtf8().data()] = Json::Value();
        }
        else if (iter.value().type() == QMetaType::Float)
        {
            rootValue[iter.key().toUtf8().data()] = iter.value().toFloat();
        }
        else if (iter.value().type() == QMetaType::Double)
        {
            rootValue[iter.key().toUtf8().data()] = iter.value().toDouble();
        }

        iter++;
    }

    return rootValue;
}
