#include <My_Filter.h>

#define WIDTH_NUM 51
#define FIL_ITEM  10

float filter_tmp[FIL_ITEM][WIDTH_NUM ];
float filter_out[FIL_ITEM];

uint8_t fil_cnt[FIL_ITEM],fil_cnt_old[FIL_ITEM];

float Moving_Average(uint8_t item,uint8_t width_num,float in)
{
    if(item >= FIL_ITEM || width_num >= WIDTH_NUM )
    {
        return 0;
    }
    else
    {
        if( ++fil_cnt[item] > width_num )
        {
            fil_cnt[item] = 0;
            fil_cnt_old[item] = 1;
        }
        else
        {
            fil_cnt_old[item] = (fil_cnt[item] == width_num)? 0 : (fil_cnt[item] + 1);
        }

        filter_tmp[item][ fil_cnt[item] ] = in;
        filter_out[item] += ( in - ( filter_tmp[item][ fil_cnt_old[item] ]  ) )/(float)( width_num ) ;//+ 0.01 *filter_out[item]

        return ( filter_out[item] );
    }

}

#define MED_WIDTH_NUM 11
#define MED_FIL_ITEM  2

float med_filter_tmp[MED_FIL_ITEM][MED_WIDTH_NUM ];
float med_filter_out[MED_FIL_ITEM];

uint8_t med_fil_cnt[MED_FIL_ITEM];

float Moving_Median(uint8_t item, uint8_t width_num,float in)
{
    uint8_t i,j;
	float t;
	float tmp[MED_WIDTH_NUM];
	
	if(item >= MED_FIL_ITEM || width_num >= MED_WIDTH_NUM )
	{
		return 0;
	}
	else
	{
		if( ++med_fil_cnt[item] >= width_num )	
		{
			med_fil_cnt[item] = 0;
		}
		
		med_filter_tmp[item][ med_fil_cnt[item] ] = in;
		
		for(i=0;i<width_num;i++)
		{
			tmp[i] = med_filter_tmp[item][i];
		}
		
		for(i=0;i<width_num-1;i++)
		{
			for(j=0;j<(width_num-1-i);j++)
			{
				if(tmp[j] > tmp[j+1])
				{
					t = tmp[j];
					tmp[j] = tmp[j+1];
					tmp[j+1] = t;
				}
			}
		}

		
		return ( tmp[(uint16_t)width_num/2] );
	}
}

