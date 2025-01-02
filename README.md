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
  ```C++
    #include <QMetaType>
    Q_DECLARE_METATYPE(LyricResult) //类中 声明 LyricResult 为元类型
    qRegisterMetaType<LyricResult>("LyricResult");
  ```
- 发现一个问题，从推荐窗口跨QListWidget切换到我的音乐QListWidget的时候有问题，切换不过来，得先选中QListWidget中的项才行
  ```   
   connect(ui->recommendListWidget, &QListWidget::currentRowChanged, this, [this, recommendOffset](int index) {
          qDebug() << "recommendListWidget index changed:" << index;
          ui->mainCenterStackedWidget->setCurrentIndex(recommendOffset + index);
      });

      connect(ui->myMusicListWidget, &QListWidget::currentRowChanged, this, [this, musicListOffset](int index) {
          qDebug() << "myMusicListWidget index changed:" << index;
          ui->mainCenterStackedWidget->setCurrentIndex(musicListOffset + index);
      });
  ```

  替换(因为从一个QListWidget切换到另一个QListWidget没有引起currentRowChanged的变化)

  ```
      connect(ui->recommendListWidget, &QListWidget::itemClicked, this, [this, recommendOffset](QListWidgetItem* item) {
        int index = ui->recommendListWidget->row(item);
        ui->mainCenterStackedWidget->setCurrentIndex(recommendOffset + index);
    });

    connect(ui->myMusicListWidget, &QListWidget::itemClicked, this, [this, musicListOffset](QListWidgetItem* item) {
        int index = ui->myMusicListWidget->row(item);
        ui->mainCenterStackedWidget->setCurrentIndex(musicListOffset + index);
    });
  ```
---

  **2024-12-31**
- 完成暂停和开始
- 上一首和下一首存在问题，不能正确处理
---

  **2024-12-31**
- 修复切换歌曲歌词没有显示问题
- 修复上一首和下一首问题
- 添加滑动进度条
- 添加调整音量