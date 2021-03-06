/**
 * @file plot_pointer_function.c
 * @author Gobikumaar Sivagnanam
 * @brief Function to plot data from the Global Pointer data
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "plotfunctions.h"

plot_check plot_pointer_function(double *xCoordinates, double *yCoordinates, int dataCount){

	RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

	//double value = 0,resolution = 0.09, limit = 1000;
	
    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = xCoordinates;
	series->xsLength = dataCount;
	series->ys = yCoordinates;
	series->ysLength = dataCount;
	series->linearInterpolation = true;
	series->lineType = L"solid";
	series->lineTypeLength = wcslen(series->lineType);
	series->lineThickness = 2;
	series->color = CreateRGBColor(0, 0, 1);

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 600;
	settings->height = 400;
	settings->autoBoundaries = true;
    //settings->xMax = 10;
    //settings->xMin = -10;
    //settings->yMax = 3;
    //settings->yMin = -3;
	settings->autoPadding = true;
	settings->title = L"";
	settings->titleLength = wcslen(settings->title);
	settings->xLabel = L"";
	settings->xLabelLength = wcslen(settings->xLabel);
	settings->yLabel = L"";
	settings->yLabelLength = wcslen(settings->yLabel);
	ScatterPlotSeries *s [] = {series};
	settings->scatterPlotSeries = s;
	settings->scatterPlotSeriesLength = 1;

	DrawScatterPlotFromSettings(imageReference, settings);

	size_t length;
	double *pngdata = ConvertToPNG(&length, imageReference->image);
	WriteToFile(pngdata, length, "plot_pointer_function_check.png");
	DeleteImage(imageReference->image);

	free(xCoordinates);
	free(yCoordinates);

	return testWritePNG("pointer_function_plot_check.png");
}