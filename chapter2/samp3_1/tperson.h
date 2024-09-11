#ifndef TPERSON_H
#define TPERSON_H

#include <QObject>

class TPerson final : public QObject {
    Q_OBJECT
    /// 附加的类信息
    Q_CLASSINFO("author", "aaron");
    Q_CLASSINFO("compay", "aaron's");
    Q_CLASSINFO("version", "0.0.1");
    Q_PROPERTY(QString name MEMBER _name); /// 私有属性，仅通过property和setProperty读写
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged) /// 公共属性，既可以使用上述函数，也可通过接口函数读写，后者更快
    Q_PROPERTY(int score MEMBER _score);

private:
    int     _age   = 1;
    int     _score = 66;
    QString _name;

public:
    explicit TPerson(QString name, QObject* parent = nullptr);

    ~TPerson() override;

    [[nodiscard]] int age() const; /// age公共接口函数【不能起别名】
                                   /// 返回值不应该被忽略

    void setAge(int age); /// 设置age属性值并发送信号

    void IncreaseAge(); /// 自增岁数并发送信号

signals:
    void ageChanged(int age);
};

#endif  // TPERSON_H