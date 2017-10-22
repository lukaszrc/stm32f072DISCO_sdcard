#include "sd_card.h"
#include "stm32f0xx_hal.h"

static uint8_t SD_SendCmd(uint8_t Cmd, uint32_t Arg, uint8_t Crc, uint8_t Response);

int init_sdcard(SD_CARD *sd, SD_RESPONSE *resp)
{
	//MOSI, CS line HIGH according to config

	/*toggling clock*/

	return 1;
}




static uint8_t SD_SendCmd(uint8_t Cmd, uint32_t Arg, uint8_t Crc, uint8_t Response)
{
	return 1;
}
