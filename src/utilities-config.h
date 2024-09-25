/*
 *	Copyright (c) 2024, Signaloid.
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */

/*
 *	These constant values are taken from Equation 11 in page 15
 *	of TMAG5253 Datasheet, 2024-07-03.
 */
#define kSensorCalibrationConstantTMAG5253BA3VccNominal		(3.3)
#define kSensorCalibrationConstantTMAG5253BA3Sensitivity	(0.015)

#define kDefaultInputDistributionVoutUniformDistLow		(2.6)
#define kDefaultInputDistributionVoutUniformDistHigh		(2.8)
#define kDefaultInputDistributionVccUniformDistLow		(3.2)
#define kDefaultInputDistributionVccUniformDistHigh		(3.4)

/*
 *	Input Distributions:
 *		kInputDistributionIndexVout	: Ratiometric Analog Voltage Output (in Volt)
 *		kInputDistributionIndexVcc	: Supply Voltage (in Volt)
 */
typedef enum
{
	kInputDistributionIndexVout	= 0,
	kInputDistributionIndexVcc	= 1,
	kInputDistributionIndexMax,
} InputDistributionIndex;

/*
 *	Output Distribution:
 *		kOutputDistributionIndexCalibratedMagneticFluxDensity	: Calibrated Magnetic Flux Density (in mT)
 */
typedef enum
{
	kOutputDistributionIndexCalibratedMagneticFluxDensity	= 0,
	kOutputDistributionIndexMax,
} OutputDistributionIndex;
