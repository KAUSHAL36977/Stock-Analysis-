# Stock Analysis Bot (C++)

This C++ program calculates Simple Moving Averages (SMA) and Relative Strength Index (RSI) from historical stock data stored in a CSV file.

## Features
- Read stock data from a CSV file.
- Calculate Simple Moving Average (SMA) and Relative Strength Index (RSI).
- Display the analysis results in a tabular format.

## Requirements
- A C++ compiler (e.g., `g++`).
- A CSV file containing historical stock data.

## Setup

### 1. Prepare CSV File
The CSV file should contain the following columns:
- `Date`
- `Open`
- `High`
- `Low`
- `Close`
- `Volume`

Each row should represent a daily stock record.

### 2. Code Setup
1. Save the provided C++ code in a file named `StockAnalysis.cpp`.
2. To compile the code, run the following command:  
   `g++ StockAnalysis.cpp -o StockAnalysis`
3. Run the compiled program using the command:  
   `./StockAnalysis`

## Code Overview

### Read Data from CSV
The `readStockData` function reads stock data from a CSV file and stores it in a vector of `StockData` structures.

### Calculate SMA
The `calculateSMA` function calculates the Simple Moving Average (SMA) based on the closing prices over a given window size.

### Calculate RSI
The `calculateRSI` function computes the Relative Strength Index (RSI) by comparing average gains to average losses over a set period (default 14 days).

### Display Results
The `displayAnalysis` function outputs the stock data, along with the calculated SMA and RSI, in a tabular format.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
