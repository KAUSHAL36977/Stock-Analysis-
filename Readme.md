# Stock Analysis Bot (C++)

This C++ program is designed to perform stock analysis by calculating two essential technical indicators: Simple Moving Average (SMA) and Relative Strength Index (RSI). The analysis is based on historical stock data that is read from a CSV file. It is a useful tool for understanding the price trends and momentum of a stock over time.

## Features
- **Data Import**: Read historical stock data from a CSV file.
- **SMA Calculation**: Compute the Simple Moving Average (SMA) to smooth out short-term price fluctuations.
- **RSI Calculation**: Calculate the Relative Strength Index (RSI) to measure the speed and change of price movements.
- **Results Display**: Display the calculated SMA and RSI along with the original stock data in a tabular format for easy analysis.

## Requirements
Before running the program, ensure that you have the following:
- **C++ Compiler**: A C++ compiler like `g++` or any standard C++ development environment.
- **CSV File**: A CSV file that contains the stock data. The data should include columns like `Date`, `Open`, `High`, `Low`, `Close`, and `Volume`.

### Libraries Used
The program uses the following C++ standard libraries:
- `fstream`: For reading the CSV file and writing outputs.
- `vector`: For storing stock data and calculated values dynamically.
- `sstream`: For parsing CSV data.
- `algorithm`: For sorting or manipulating data if required.

## Setup

### 1. **Prepare the Stock Data CSV**
The CSV file should have the following columns:
- `Date`: The date of the stock data entry.
- `Open`: The stock price at the opening of the trading day.
- `High`: The highest price during the trading day.
- `Low`: The lowest price during the trading day.
- `Close`: The closing price at the end of the trading day.
- `Volume`: The total number of shares traded.

Each row should represent one day's data.

Example of the CSV format:
```csv
Date,Open,High,Low,Close,Volume
2023-01-01,150,155,148,152,1000000
2023-01-02,153,157,151,155,1100000
2023-01-03,155,160,152,158,1200000

### 2. **Code Setup**

1. **Save the Code**: Save the provided C++ code into a file named `StockAnalysis.cpp`.
   
2. **Compile the Code**:
   After saving the code, open a terminal or command prompt and navigate to the directory containing the file. Then, compile the code using the following command:
   ```
   g++ StockAnalysis.cpp -o StockAnalysis
   ```

3. **Run the Program**:
   After successful compilation, run the program using the command:
   ```
   ./StockAnalysis
   ```

   This will execute the stock analysis, read the data from the CSV file, calculate the SMA and RSI, and display the results.

### 3. **CSV File Path**
Ensure that the CSV file (`stock_data.csv`) is in the same directory as the executable, or specify the correct path in the code if it's located elsewhere.

## How the Program Works

### **1. Reading Stock Data from CSV**
The `readStockData` function is responsible for reading the stock data from the CSV file. It parses each row of the file and stores the stock information into a vector of `StockData` structures. Each `StockData` structure contains:
- `date`: The date of the stock data entry.
- `open`: The opening price of the stock.
- `high`: The highest price during the trading day.
- `low`: The lowest price during the trading day.
- `close`: The closing price of the stock.
- `volume`: The trading volume for the day.

### **2. Calculating Simple Moving Average (SMA)**
The `calculateSMA` function calculates the Simple Moving Average for the stock's closing prices over a specified window. The SMA helps to smooth out fluctuations in stock prices, making it easier to identify trends. It takes in a window size (e.g., 50 days) and the stock data, and returns a vector of calculated SMA values.

### **3. Calculating Relative Strength Index (RSI)**
The `calculateRSI` function calculates the Relative Strength Index (RSI) for the stock's closing prices. The RSI measures the strength of a stock's price momentum by comparing the magnitude of recent gains to recent losses. It typically uses a period of 14 days to compute the average gains and losses. The RSI helps to determine whether a stock is overbought or oversold.

### **4. Displaying the Results**
The `displayAnalysis` function takes the stock data, SMA, and RSI values and outputs them in a tabular format. The program will display:
- The date of each stock entry.
- The closing price.
- The calculated SMA (if available for that date).
- The RSI value (if available for that date).

The table will look like this:
```
Date        Close   SMA_50  RSI_14
2023-01-01  152     N/A     N/A
2023-01-02  155     N/A     N/A
2023-01-03  158     154.0   62.5
...
```

## Example Output

When you run the program with your stock data, you will see an output similar to the following:

```
Date        Close   SMA_50  RSI_14
2023-01-01  152     N/A     N/A
2023-01-02  155     N/A     N/A
2023-01-03  158     154.0   62.5
2023-01-04  160     155.5   64.0
...
```

This table shows the calculated SMA and RSI alongside the stock's daily closing prices. The SMA is only calculated after the specified window size is met, and the RSI is calculated based on the period selected.

## How to Extend

- **Add More Technical Indicators**: You can extend this program by adding more technical analysis indicators such as MACD, Bollinger Bands, or Moving Average Convergence Divergence.
- **Real-Time Data Integration**: Integrate APIs like Alpha Vantage, Yahoo Finance, or Quandl to fetch real-time stock data instead of using a static CSV file.
- **Automated Alerts**: Implement features that send alerts when the SMA or RSI crosses a predefined threshold, helping users make timely trading decisions.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```

This version provides a detailed explanation of each aspect of the project, including setup, functionality, and how the program works step by step. It also suggests ways to extend the functionality for further development.
