# 项目日志
---
**2024-12-22**
- 简单开发出了解析歌词并显示歌词
- 但是存在很大问题
  - 切换歌曲的时候歌词没有更新
  - 高品质歌曲无法播放，会导致程序崩溃
---

**2024-12-26**
- 完成数据库sqlite的建立
- 本地音乐可以从数据库查询
- 修复切换歌曲没有显示问题，但是又引出一个加上锁播放歌曲会导致程序崩溃
---

**2024-12-27**
- 修复切换歌曲的时候歌词没有更新，以及切歌崩溃的问题
  - <span style="color:red;"> 
    由于歌词解析类属于嵌套类，不能使用Qt的信号与槽，所以得把歌词解析类提取出来</span> 
  - <span style="color:red;"> 
    需要在信号与槽传递自定义的类，需要在程序中注册元类型 </span> 

  ```C#
    #include <QMetaType>
    Q_DECLARE_METATYPE(LyricResult) //类中 声明 LyricResult 为元类型
    qRegisterMetaType<LyricResult>("LyricResult");
  ```