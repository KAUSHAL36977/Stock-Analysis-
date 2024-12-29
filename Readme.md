Here is the `README.md` file for the C++ stock analysis program:

```markdown
# Stock Analysis Bot (C++)

This C++ program analyzes stock data by calculating technical indicators such as the Simple Moving Average (SMA) and the Relative Strength Index (RSI) from historical stock data. The stock data is read from a CSV file containing the stock's daily information.

## Features
- Read historical stock data from a CSV file.
- Calculate Simple Moving Averages (SMA) for stock closing prices.
- Calculate Relative Strength Index (RSI) for stock price momentum.
- Display the analysis results in a tabular format.

## Requirements

Before you begin, ensure you have the following:
- A C++ compiler (e.g., `g++`)
- A CSV file with stock data (see below for the required format)

### Libraries Used:
- `fstream` for file handling
- `vector` for dynamic arrays
- `sstream` for string manipulation
- `algorithm` for sorting (if needed)

## Setup

### 1. **Prepare the Stock Data CSV**

The stock data should be in a CSV format with the following columns:

```csv
Date,Open,High,Low,Close,Volume
```

Example:

```csv
Date,Open,High,Low,Close,Volume
2023-01-01,150,155,148,152,1000000
2023-01-02,153,157,151,155,1100000
2023-01-03,155,160,152,158,1200000
...
```

Save your file as `stock_data.csv`.

### 2. **Code Setup**

1. **Save the Code**: Save the provided C++ code in a file named `StockAnalysis.cpp`.

2. **Compile the Code**: To compile the C++ code, use the following command:
   ```bash
   g++ StockAnalysis.cpp -o StockAnalysis
   ```

3. **Run the Program**: After compilation, you can run the program using:
   ```bash
   ./StockAnalysis
   ```

### 3. **CSV File Path**
Ensure that your stock data CSV file (`stock_data.csv`) is in the same directory as the program, or specify the correct path in the code.

## Functions

### 1. **`readStockData(const std::string &filename)`**

This function reads stock data from a CSV file and returns a vector of `StockData` structs.

- **Input**: CSV file path.
- **Output**: Vector of `StockData` structs containing the stock data.

### 2. **`calculateSMA(const std::vector<StockData> &data, int window)`**

This function calculates the Simple Moving Average (SMA) for the stock closing prices.

- **Input**: A vector of `StockData` and the window size (e.g., 50 days).
- **Output**: A vector of SMA values.

### 3. **`calculateRSI(const std::vector<StockData> &data, int period)`**

This function calculates the Relative Strength Index (RSI) for the stock closing prices.

- **Input**: A vector of `StockData` and the period (default is 14).
- **Output**: A vector of RSI values.

### 4. **`displayAnalysis(const std::vector<StockData> &data, const std::vector<double> &sma, const std::vector<double> &rsi)`**

This function displays the stock data along with the calculated SMA and RSI.

- **Output**: Displays the Date, Closing Price, SMA (if available), and RSI (if available) in a table format.

## Example Output

```text
Date        Close   SMA_50  RSI_14
2023-01-01  152     N/A     N/A
2023-01-02  155     N/A     N/A
2023-01-03  158     N/A     N/A
...
```

## How to Extend

- **More Technical Indicators**: You can add more technical analysis methods like MACD, Bollinger Bands, etc.
- **Real-Time Data**: Integrate APIs like Alpha Vantage or Quandl to fetch real-time stock data instead of using a static CSV file.
- **Automated Alerts**: Set alerts based on certain thresholds for SMA, RSI, or other indicators.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```

This `README.md` file explains the setup, usage, and structure of the C++ stock analysis program. It also provides instructions on how to run the program and extend it for more advanced features.
