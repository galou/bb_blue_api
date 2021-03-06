/*******************************************************************************
* test_adc.c
*
* James Strawson 2016
* prints voltages read by all adc channels
*******************************************************************************/

#include <bb_blue_api.h>

int main(){
	int i;
		
	initialize_board();
	
	printf(" adc_0 |");
	printf(" adc_1 |");
	printf(" adc_2 |");
	printf(" adc_3 |");
	printf("DC_Jack|");
	printf("Battery|");
	
	printf("\n");
	

	while(get_state()!=EXITING){
		printf("\r");
		//print all channels
		for(i=0;i<4;i++){
			printf("%6.2f |", get_adc_volt(i));
		}
		printf("%6.2f |", get_dc_jack_voltage());
		printf("%6.2f |", get_battery_voltage());
		fflush(stdout);
		usleep(100000);
	}
	cleanup_board();
	return 0;
}