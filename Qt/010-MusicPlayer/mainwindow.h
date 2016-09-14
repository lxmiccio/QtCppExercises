#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListWidget>
#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    QMediaPlayer* mediaPlayer;
    QMediaPlaylist* mediaPlaylist;
    QProgressBar* progressBar;
    QListWidget* listWidget;
    QPushButton* play;
    QPushButton* stop;
    QPushButton* addSong;
    QPushButton* addDirectory;

public:
    explicit MainWindow(QWidget *parent = 0);

public slots:
    void progressBarChanged(qint64);
    void playClicked();
    void stopClicked();
    void addSongClicked();
    void addDirectoryClicked();
};

#endif // MAINWINDOW_H
