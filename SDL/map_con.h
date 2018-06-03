#pragma once

double *egw(int i)
{
	return &(flt[me_x][me_y][i]);
}
double eg(int i)
{
	return (flt[me_x][me_y][i]);
}

double *vsw(int i)
{
	return &(flt[yu_x][yu_y][i]);
}
double vs(int i)
{
	return (flt[yu_x][yu_y][i]);
}

void all_rand()
{
	for (int a = 0; a < map_w; a++)
	{
		for (int b = 0; b < map_h; b++)
		{
			for (int i = 0; i < map_opt; i++)
			{
				tip[a][b][i] = 0;
				flt[a][b][i] = random();
			}
			flt[a][b][fl_height] = flt[a][b][fl_height] - 0.5;
			flt[a][b][fl_wat] = flt[a][b][fl_wat] / 2;// -0.5;
			flt[a][b][fl_wat_angle] = M_PI;
			flt[a][b][fl_wat_speed] = 1;
		}
	}
}
void stair_height()
{
	for (int a = 0; a < map_w; a++)
	{
		for (int b = 0; b < map_h; b++)
		{
			flt[a][b][fl_height] = (10 * a / (map_w - 1)) / 10.0;// +sin(b) / 10;
		}
	}
}
void water_flow()
{
	tmp2[0] = (eg(fl_height) + eg(fl_wat)) - (vs(fl_height) + vs(fl_wat));
	if (tmp2[0] > 0)
	{
		tmp2[0] = reru(tmp2[0] / eg(fl_wat)) * eg(fl_wat);
		*egw(fl_wat) -= tmp2[0];
		*vsw(fl_wat) += tmp2[0];
	}
	// = 0;
}
void gnd_flow()
{
	tmp2[0] = (eg(fl_height)) - (vs(fl_height));
	if (tmp2[0] > 0)
	{
		tmp2[0] = tmp2[0] * 0.5;
		flt[me_x][me_y][fl_height] -= tmp2[0];
		flt[yu_x][yu_y][fl_height] += tmp2[0];
		//std::cout << tmp2[0];
	}
	// = 0;
}