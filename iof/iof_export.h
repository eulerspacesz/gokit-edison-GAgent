#ifndef __IOF_EXPORT_H__
#define __IOF_EXPORT_H__
/************************************************************
 *IOF EXPORT FUNCS FOR LIB
 * �ҽӹ��ӵĳ�ʼ������
 ************************************************************
 ***********************************************************/

/* product ��صĺ궨�� */
#define WIFI_HARD_VERSION "00x86-os"
#define WIFI_HARDVER    "00x86-os"
#define WIFI_SOFTVAR    "04000001"

//product key len is 32 byte
#define GAGENT_PRODUCT_KEY  "1a4e1b253a094e7586ca9d74a4e03597"
#ifndef GAGENT_PRODUCT_KEY
#error "product key hasn't be defined!please define product key!!!"
#endif

extern void IOF_Config_hook_init(void);
extern void IOF_General_Hook_Init(void);

#endif  /* __IOF_EXPORT_H__ */
