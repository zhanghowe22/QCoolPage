﻿/*****************************************
 * 作者: YYC
 * 日期: 2021-01-07
 * 功能：初始化类
 * ***************************************/
#include "mainobject.h"

#include <QDebug>

#include "mainwindow.h"
#include "splashscreen.h"

MainObject::MainObject(QObject* parent) : QObject(parent) {}

MainObject::~MainObject() { delete m_mainWindow; }

void MainObject::setInit() {
    SplashScreen::getInstance()->setStagePercent(0, tr("初始化应用程序 ..."));
    m_mainWindow = new MainWindow(nullptr);
    m_mainWindow->setWindowTitle(tr("DataAnalyze"));
    m_mainWindow->setWindowIcon(QIcon(":/res/res/image/icon.png"));

    SplashScreen::getInstance()->setStart(m_mainWindow, tr("DataAnalyze"), QString(":/res/res/image/icon.png"));
    SplashScreen::getInstance()->setStagePercent(40, tr("初始化主界面 ..."));
    SplashScreen::getInstance()->setStagePercent(80, tr("加载界面 ..."));
    SplashScreen::getInstance()->setStagePercent(100, tr("加载完毕！"));
    SplashScreen::getInstance()->setFinish();

    m_mainWindow->showNormal();
}
