#pragma once

double calc_total_meal_price(double meal_price) { // header(parameter), void is the return type
	// function body

	double const LEE_COUNTY_TAX_RATE = .065; // named constant to avoid "magic numbers"

	double tax = meal_price * LEE_COUNTY_TAX_RATE; // local variables
	double tip = meal_price * .15;

	double total_price = meal_price + tax + tip;

	return total_price;

}