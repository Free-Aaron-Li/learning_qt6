#include "tperson.h"

#include <utility>

TPerson::TPerson(QString name, QObject* parent) { _name = std::move(name); }

TPerson::~TPerson() {
    qDebug("TPerson已经被删除了。"); /// 显示信息，查看对象是否被删除
}

int
TPerson::age() const { return _age; }

void
TPerson::setAge(const int age) {
    if (_age != age) {
        _age = age;
        emit ageChanged(_age);
    }
}

void
TPerson::IncreaseAge() {
    ++_age;
    emit ageChanged(_age);
}