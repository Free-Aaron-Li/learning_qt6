# 第4章 常用界面组件的使用

## 4.4 [QSpinBox](https://doc.qt.io/qt-6/qspinbox.html)和[QDoubleSpinBox](https://doc.qt.io/qt-6/qdoublespinbox.html)

常用当数值输入和输出组件。

一个属性在类的接口中一般有一个读取函数和设置函数，
```c++
int QSpinBox::value();              // 读取数值
void QSpinBox::setValue(int val);   // 设置数值
```

