#include <ATX2.h>

/**
 * @file atx-robot.cpp
 * @brief โปรแกรมควบคุมหุ่นยนต์เดินตามเส้นพร้อมความสามารถในการส่งพัสดุ
 */

// ค่าคงที่สำหรับการปรับแต่งมอเตอร์
const int LEFT_BIAS = 0;    // ค่าปรับแต่งสำหรับมอเตอร์ซ้าย
const int RIGHT_BIAS = 1;  // ค่าปรับแต่งสำหรับมอเตอร์ขวา

// ค่าขีดแบ่งแสงสำหรับเซนเซอร์ตรวจจับเส้น
const int SENSOR_BLACK_0 = 500;  // ค่าขีดแบ่งแสงสำหรับเซนเซอร์ 1 (ค่าต่ำกว่านี้ถือว่าเป็นสีดำ)
const int SENSOR_BLACK_1 = 500;  // ค่าขีดแบ่งแสงสำหรับเซนเซอร์ 2 (ค่าต่ำกว่านี้ถือว่าเป็นสีดำ)
const int SENSOR_BLACK_2 = 500;  // ค่าขีดแบ่งแสงสำหรับเซนเซอร์ 3 (ค่า>ต่ำกว่านี้ถือว่าเป็นสี>>ดำ)
const int SENSOR_BLACK_3 = 500;  // ค่าขีดแบ่งแสงสำหรับเซนเซอร์ 4 (ค่าต่ำกว่านี้ถือว่าเป็นสีดำ)

// ค่าคงที่สำหรับการหมุนตัวของหุ่นยนต์
const int TURN_LEFT_DELAY = 300;          // ระยะเวลาในการหมุนซ้าย (มิลลิวินาที)
const int TURN_RIGHT_DELAY = 300;         // ระยะเวลาในการหมุนขวา (มิลลิวินาที)
const int TURN_LEFT_AROUND_DELAY = 490;   // ระยะเวลาในการหมุนซ้ายรอบตัว (มิลลิวินาที)
const int TURN_RIGHT_AROUND_DELAY = 490;  // ระยะเวลาในการหมุนขวารอบตัว (มิลลิวินาที)
const int TURN_POWER = 50;                // กำลังมอเตอร์ที่ใช้ในการหมุนตัว (0-100)

// ค่าคงที่สำหรับการเช็คเส้นของหุ่นยนต์
const int LINE_UNIT_DELAY = 220;       // ระยะเวลาในการเคลื่อนที่กลับ (มิลลิวินาที)
const int LINE_UNIT_BACK_POWER = 42;   // กำลังมอเตอร์กลับที่ใช้ในการเคลื่อนที่ (0-100)
const int LINE_UNIT_CHECK_POWER = 42;  // กำลังมอเตอร์เช็คที่ใช้ในการเคลื่อนที่ (0-100)

const int msd = 225;  // ระยะเวลาในการเคลื่อนที่ (มิลลิวินาที)
const int msp = 67;   // กำลังมอเตอร์ที่ใช้ในการเคลื่อนที่ (0-100)

/**
 * @brief ฟังก์ชันตั้งค่าที่ทำงานครั้งเดียวเมื่อเริ่มต้น
 */
void setup() {
  OK();
  glcdClear();
  servo(1, -1);
  setTextSize(2);
  ao();
  delay(800);

  // mf(msd * 2.3, msp + 5);mfub();tr(false, -10);mbub();mf(msd * 1.7, msp);mfub();tr(false, -10);mbub();
  // mf(msd + 20, msp);tr(false, -10);mbub();mfub();tl(false, -40);mbub();mf(msd * 1.3, msp);mfub();dp();

  // mb(msd * 0.65, msp);tl(false, -40);mbub();mf(msd * 4.5, msp - 10);mfub();tl(false, -20);mf(msd * 1.4, msp);
  // mfub();tl(false, -10);mbub();mf(msd * 1.7, msp);mfub();
  
  // tr(true, -100);mbub();mf(msd * 1.7, msp);mfub();tr(false, -18.5);mbub();mf(msd + 1.2, msp);tl(false, 0);
  // mbub();smf();mfub();tl(false, -20);mfub();tl(false, -45);mbub();mfub();dp();
  
  // mbub();mf(msd * 0.2, msp);tl(false, -35);mbub();mf(msd * 2, msp);mfub();dp();
  
  // mb(msd * 0.85, msp);tr(false, -10);mbub();mfub();mbub();tr(false, -35);mf(msd, msp);tl(false, -10);mbub();
  // mf(msd * 0.4, msp);smf();/**/mfub();mb(msd * 0.5, msp);tl(false, -35);mf(msd + 1.2, msp);mfub();tr(false, -35);
  // mbub();mf(msd + 1.2, msp);mfub();dp();

  // tl(true, 0);mbub();mf(msd + 1.2, msp);mfub();tl(false, -10);mbub();mb(msd * 0.85, msp);tl(false, -10);
  // mf(msd * 4.5, msp - 10);mfub();tr(false, -10);mfub();tl(false, -10);mbub();mfub();tl(false, -10);
  // mf(msd * 1.7, msp);mfub();tl(false, -10);mbub();mf(msd * 2.5, msp + 5);
}

/**
 * @brief ฟังก์ชันลูปหลัก
 */
void loop() {
  // testSensors();
  // adjustServo();
}

/**
 * @brief เคลื่อนที่ไปข้างหน้าแบบช้าข้ามผิวขรุขระ
 */
void smf() {
  fd2(30 + LEFT_BIAS, 30 + RIGHT_BIAS);
  delay(1000);
  fd2(40 + LEFT_BIAS, 40 + RIGHT_BIAS);
  delay(1000);
  ao();
}

/**
 * @brief เคลื่อนที่ไปข้างหน้าหลังพร้อมการเร่งและชะลอความเร็ว
 * @param duration ระยะเวลาของการเคลื่อนที่ด้วยความเร็วเต็มที่
 * @param power ความเร็วสูงสุดของการเคลื่อนที่ถอยหลัง
 */
void mf(int duration, int power) {
  fd2(power / 3 + LEFT_BIAS, power / 3 + RIGHT_BIAS);
  delay(duration / 4);
  fd2(power / 2 + LEFT_BIAS, power / 2 + RIGHT_BIAS);
  delay(duration / 3);
  fd2(power + LEFT_BIAS, power + RIGHT_BIAS);
  delay(duration);
  fd2(power / 2 + LEFT_BIAS, power / 2 + RIGHT_BIAS);
  delay(duration / 3);
  fd2(power / 3 + LEFT_BIAS, power / 3 + RIGHT_BIAS);
  delay(duration / 4);
  ao();
}

/**
 * @brief เคลื่อนที่ถอยหลังพร้อมการเร่งและชะลอความเร็ว
 * @param duration ระยะเวลาของการเคลื่อนที่ด้วยความเร็วเต็มที่
 * @param power ความเร็วสูงสุดของการเคลื่อนที่ถอยหลัง
 */
void mb(int duration, int power) {
  fd2(-power / 3 - LEFT_BIAS, -power / 3 - RIGHT_BIAS);
  delay(duration / 4);
  fd2(-power / 2 - LEFT_BIAS, -power / 2 - RIGHT_BIAS);
  delay(duration / 3);
  fd2(-power - LEFT_BIAS, -power - RIGHT_BIAS);
  delay(duration);
  fd2(-power / 2 - LEFT_BIAS, -power / 2 - RIGHT_BIAS);
  delay(duration / 3);
  fd2(-power / 3 - LEFT_BIAS, -power / 3 - RIGHT_BIAS);
  delay(duration / 4);
  ao();
}

/**
 * @brief หมุนหุ่นยนต์ซ้าย
 * @param around true สำหรับหมุน 180 องศา, false สำหรับหมุน 90 องศา
 * @param difference ความต่างระหว่างโค้ง
*/
void tr(bool around, int difference) {
  ao();
  delay(100);
  sr(TURN_POWER);
  delay((around ? TURN_RIGHT_AROUND_DELAY : TURN_RIGHT_DELAY) + difference);
  ao();
  delay(100);
}

/**
 * @brief หมุนหุ่นยนต์ขวา
 * @param around true สำหรับหมุน 180 องศา, false สำหรับหมุน 90 องศา
 * @param difference ความต่างระหว่างโค้ง
*/
void tl(bool around, int difference) {
  ao();
  delay(100);
  sl(TURN_POWER);
  delay((around ? TURN_LEFT_AROUND_DELAY : TURN_LEFT_DELAY) + difference);
  ao();
  delay(100);
}


/**
 * @brief เคลื่อนที่ไปข้างหน้าจนกว่าจะพบเส้นสีดำ จากนั้นปรับตำแหน่ง
 */
void mfub() {
  while (analog(0) > SENSOR_BLACK_0 && analog(1) > SENSOR_BLACK_1) {
    fd2(LINE_UNIT_CHECK_POWER + LEFT_BIAS, LINE_UNIT_CHECK_POWER + RIGHT_BIAS);
  }
  while (analog(0) < SENSOR_BLACK_0 && analog(1) > SENSOR_BLACK_1) {
    sl(24);
  }
  while (analog(0) > SENSOR_BLACK_0 && analog(1) < SENSOR_BLACK_1) {
    sr(24);
  }
  if (analog(0) < SENSOR_BLACK_0 && analog(1) < SENSOR_BLACK_1) {
    ao();
    delay(100);
  }
  fd2(-LINE_UNIT_BACK_POWER - LEFT_BIAS, -LINE_UNIT_BACK_POWER - RIGHT_BIAS);
  delay(LINE_UNIT_DELAY);
  ao();
  delay(30);
}

/**
 * @brief เคลื่อนที่ถอยหลังจนกว่าจะพบเส้นสีดำ จากนั้นปรับตำแหน่ง
 */
void mbub() {
  while (analog(2) > SENSOR_BLACK_2 && analog(3) > SENSOR_BLACK_3) {
    fd2(-LINE_UNIT_CHECK_POWER - LEFT_BIAS, -LINE_UNIT_CHECK_POWER - RIGHT_BIAS);
  }
  while (analog(2) < SENSOR_BLACK_2 && analog(3) > SENSOR_BLACK_3) {
    sr(24);
  }
  while (analog(2) > SENSOR_BLACK_2 && analog(3) < SENSOR_BLACK_3) {
    sl(24);
  }
  if (analog(2) < SENSOR_BLACK_2 && analog(3) < SENSOR_BLACK_3) {
    ao();
    delay(100);
  }
  fd2(LINE_UNIT_BACK_POWER + LEFT_BIAS, LINE_UNIT_BACK_POWER + RIGHT_BIAS);
  delay(LINE_UNIT_DELAY);
  ao();
  delay(30);
}

/**
 * @brief ปล่อยพัสดุโดยใช้เซอร์โวมอเตอร์
 */
void dp() {
  fd2(LINE_UNIT_BACK_POWER + LEFT_BIAS, LINE_UNIT_BACK_POWER + RIGHT_BIAS);
  delay(LINE_UNIT_DELAY);
  ao();
  servo(1, 180);
  sleep(450);
  servo(1, 70);
  sleep(450);
  servo(1, -1);
  delay(30);
}

/**
 * @brief ทดสอบและแสดงค่าจากเซนเซอร์
 */
void testSensors() {
  glcd(0, 0, "FL=%d  ", analog(0));
  glcd(1, 0, "FR=%d  ", analog(1));
  glcd(2, 0, "BL=%d  ", analog(2));
  glcd(3, 0, "BR=%d  ", analog(3));
}

/**
 * @brief ปรับตำแหน่งเซอร์โวโดยใช้ปุ่มหมุน
 */
void adjustServo() {
  int knobPosition = knob(180);
  servo(1, knobPosition);
  glcd(1, 1, "%d   ", knobPosition);
}