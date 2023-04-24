//
// Created by deb on 17.06.22.
//

#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include "Serializer.h"
#include <fstream>

Serializer::Serializer(const IKomponente &root) : ik{root} {}

void Serializer::writeToJson(const char *fname) {
    QFile saveFile(fname);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        throw std::fstream::failure( "Datei konnte nicht geoeffnet werden." );
    }

    auto jsonObject = ik.toJson();
    auto bytes_written = saveFile.write(QJsonDocument(jsonObject).toJson());
    if(bytes_written == -1) {
        throw std::fstream::failure( "Datei konnte nicht beschrieben werden." );
    }

}
