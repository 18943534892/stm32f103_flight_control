#ifndef _PID
#define _PID
#include "sys.h"
#include "control_recode.h"

#define DEFAULT_PID_INTEGRATION_LIMIT  100.0
#define YM_Dead 1105

//************�⻷pid����**************************//
#define PID_OUT_PITCH_KP  2.5 //2.5
#define PID_OUT_PITCH_KI  0   //0
#define PID_OUT_PITCH_KD  0   //0
#define PID_OUT_PITCH_INTEGRATION_LIMIT   500.0 // 500.0

#define PID_OUT_ROLL_KP  3    //3
#define PID_OUT_ROLL_KI  0    //0
#define PID_OUT_ROLL_KD  0    //0
#define PID_OUT_ROLL_INTEGRATION_LIMIT    500.0 // 500.0


//************�ڻ�pid����**************************//
#define PID_IN_PITCH_KP  0.5     //0.5
#define PID_IN_PITCH_KI  0.003   //0.003
#define PID_IN_PITCH_KD  0.25    //0.25
#define PID_IN_PITCH_INTEGRATION_LIMIT   500.0 // 500.0

#define PID_IN_ROLL_KP  0.3      //0.3
#define PID_IN_ROLL_KI  0.003    //0.003
#define PID_IN_ROLL_KD  0.20     //0.20
#define PID_IN_ROLL_INTEGRATION_LIMIT    500.0 // 500.0

#define PID_IN_YAW_KP   3        //3.0
#define PID_IN_YAW_KI   0        //0
#define PID_IN_YAW_KD   0        //0
#define PID_IN_YAW_INTEGRATION_LIMIT   200.0 // 200.0

typedef struct
{
  float desired;      //< ����������ֵ
  float error;        //< ����ֵ-ʵ��ֵ
  float prevError;    //< ǰһ��ƫ��
  float integ;        //< ���ֲ���
  float deriv;        //< ΢�ֲ���
  float kp;           //< ��������
  float ki;           //< ���ֲ���
  float kd;           //< ΢�ֲ���
  float outP;         //< pid�������֣�������
  float outI;         //< pid���ֲ��֣�������
  float outD;         //< pid΢�ֲ��֣�������
  float iLimit;       //< ��������
} pidsuite;

extern u8 armed;

void PID_controllerInit(void);     //pid������ʼ��
void Control(u8 armed);

#endif
