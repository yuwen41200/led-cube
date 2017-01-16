# LED Cube #

## 題目 ##

LED Cube Using STM32L476 Microcontroller

## 簡介 ##

* 製作 5x5x5 LED cube 顯示 3D 動畫。
* 離 LED cube 愈近，動畫的速度愈快。

## 系統架構 ##

## 流程圖 ##

## 功能說明 ##

* LED cube 的原理、電晶體的原理。
* 74HC595 內含一個 shift register，提供 8-bit serial-in parallel-out 的功能。只要用一個 MCU 的 GPIO pin 依序輸出八個訊號，就能同時控制八個 LED cube 的輸入。我們設計的 LED cube 一共有 30 個輸入，因此需要四個 74HC595，佔用了 MCU 六個 GPIO pin〈四個 serial data 輸出、一個共用的 input clock 輸出、一個共用的 output clock 輸出〉。
* HC-SR04 是一個超音波感測器，被觸發後，它會發送八個脈衝並等待回波。接收到回波後，它會輸出 ECHO 訊號，透過此訊號的長度可以算出物體的距離。長度愈長，距離愈遠。若過了太久仍未收到 ECHO 訊號，則會自動 timeout。我們使用 SysTick 和中斷機制，每三秒偵測一次物體的距離，並依據此距離來調整動畫的速度。距離愈近，速度愈快〈但不得超出上、下界〉。

## 成果展示 ##

## 遭遇的挑戰與解決方式 ##

## 心得 ##
