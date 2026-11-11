/*
 *	Copyright (c) 2024-2026, Signaloid.
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

#include <uxhw.h>
#include "kernel.h"
#include "tmag5253-uxhw.h"
#include "tmag5253-monte-carlo.h"

void
TexasInstrumentsTMAG5253SetInputVariablesViaUxHwCall(double * inputVariables)
{
	inputVariables[kTexasInstrumentsTMAG5253InputVariableIndexVout] = UxHwDoubleUniformDist(
		kTexasInstrumentsTMAG5253DefaultInputDistributionVoutUniformDistLow,
		kTexasInstrumentsTMAG5253DefaultInputDistributionVoutUniformDistHigh
	);

	inputVariables[kTexasInstrumentsTMAG5253InputVariableIndexVcc] = UxHwDoubleUniformDist(
		kTexasInstrumentsTMAG5253DefaultInputDistributionVccUniformDistLow,
		kTexasInstrumentsTMAG5253DefaultInputDistributionVccUniformDistHigh
	);

	return;
}

double
TexasInstrumentsTMAG5253_calculateOutput(double * inputVariables, double *  outputVariables)
{
	double  Vcc;
	double  Vout;
	double  Vq;
	double  calibratedValue;

	Vcc     = inputVariables[kTexasInstrumentsTMAG5253InputVariableIndexVcc];
	Vout    = inputVariables[kTexasInstrumentsTMAG5253InputVariableIndexVout];

	/*
	 *	For bipolar ("B") variant (TMAG5253BA3), Vq is Vcc/2.
	 */
	Vq = Vcc / 2;

	calibratedValue = (Vout - Vq) /
	                  (kTexasInstrumentsTMAG5253SensorCalibrationConstantTMAG5253BA3Sensitivity * Vcc /
	                   kTexasInstrumentsTMAG5253SensorCalibrationConstantTMAG5253BA3VccNominal);
	outputVariables[kTexasInstrumentsTMAG5253OutputVariableIndexCalibratedMagneticFluxDensity] = calibratedValue;

	return calibratedValue;
}

double
TexasInstrumentsTMAG5253CalculateOutputUxHw(double * outputVariables)
{
	return tmag5253UxHw(outputVariables);
}

double
TexasInstrumentsTMAG5253CalculateOutputMonteCarlo(
	size_t      numberOfMonteCarloIterations,
	double *    outputVariables,
	double *    monteCarloOutputSamples)
{
	return tmag5253MonteCarlo(
		numberOfMonteCarloIterations,
		outputVariables,
		monteCarloOutputSamples
	);
}
