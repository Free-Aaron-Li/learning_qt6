// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "tperson.h"
#include <utility>

TPerson::TPerson(QString name, [[maybe_unused]] QObject *parent) { _name = std::move(name); }

TPerson::~TPerson() {
    qDebug("TPerson已经被删除了。"); /// 显示信息，查看对象是否被删除
}

auto
TPerson::age() const -> int { return _age; }

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
