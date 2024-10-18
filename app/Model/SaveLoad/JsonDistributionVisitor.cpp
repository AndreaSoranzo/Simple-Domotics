#include "JsonDistributionVisitor.h"

void JsonDistributionVisitor::visit(const UniformDistribution& dist) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(dist.ToString().c_str()));
    obj.insert("amount", QJsonValue::fromVariant(dist.GetAmount()));
    obj.insert("min", QJsonValue::fromVariant(dist.GetMin()));
    obj.insert("max", QJsonValue::fromVariant(dist.GetMax()));
    json = obj;
}
void JsonDistributionVisitor::visit(const NormalDistribuition& dist) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(dist.ToString().c_str()));
    obj.insert("amount", QJsonValue::fromVariant(dist.GetAmount()));
    obj.insert("mean", QJsonValue::fromVariant(dist.GetMean()));
    obj.insert("noise", QJsonValue::fromVariant(dist.GetNoise()));
    json = obj;
}
void JsonDistributionVisitor::visit(const ExponentialDistribution& dist) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(dist.ToString().c_str()));
    obj.insert("amount", QJsonValue::fromVariant(dist.GetAmount()));
    json = obj;
}
void JsonDistributionVisitor::visit(const RandomDistribution& dist) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(dist.ToString().c_str()));
    obj.insert("amount", QJsonValue::fromVariant(dist.GetAmount()));
    obj.insert("min", QJsonValue::fromVariant(dist.GetMin()));
    obj.insert("max", QJsonValue::fromVariant(dist.GetMax()));
    json = obj;
}

QJsonObject JsonDistributionVisitor::GetJsonObject() const {
    return json;
};