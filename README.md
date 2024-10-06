# 1. 简介

> 参考：[《Qt6 C++开发指南》][1]学习以C++为主的 Qt 6 开发。本项目主要用于存储学习过程中编写的示例代码。

[1]: https://www.epubit.com/bookDetails?id=UBd1495d037530

---

# 2. 开发环境

> 工具链：gcc 14、ninja、GDB、CMake 3.29
>
> Qt 版本：6.7.2
>
> IDE：Qt Creator(14.0.1)、CLion(2024.2)
>
> C++版本：C++17

---

# 3. 编译

## 3.1 IDE构建

本项目通过CLion实现项目管理，可以直接通过下载或克隆本项目后通过CLion或VScode构建。

## 3.2 CMake构建

进入本项目，执行如下命令：

```bash
mkdir build && cd build
cmake ..
make install
```

构建完成后，将会在顶层项目下生成`bin`目录，其中包含各章节实现的可执行程序。

完整的单元项目`CMakeLists.txt`配置文件可在[samp2_3][2]中查看。

[2]:./chapter2/samp2_3/CMakeLists.txt

