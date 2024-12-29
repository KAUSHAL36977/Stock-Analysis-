#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

// Struct to store stock data
struct StockData {
    std::string date;
    double open;
    double high;
    double low;
    double close;
    double volume;
};

// Function to read stock data from CSV
std::vector<StockData> readStockData(const std::string &filename) {
    std::vector<StockData> data;
    std::ifstream file(filename);
    std::string line;
    
    // Skip header
    std::getline(file, line);

    // Read the data line by line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, open, high, low, close, volume;
        StockData stock;

        std::getline(ss, date, ',');
        std::getline(ss, open, ',');
        std::getline(ss, high, ',');
        std::getline(ss, low, ',');
        std::getline(ss, close, ',');
        std::getline(ss, volume, ',');

        stock.date = date;
        stock.open = std::stod(open);
        stock.high = std::stod(high);
        stock.low = std::stod(low);
        stock.close = std::stod(close);
        stock.volume = std::stod(volume);

        data.push_back(stock);
    }

    file.close();
    return data;
}

// Function to calculate the Simple Moving Average (SMA)
std::vector<double> calculateSMA(const std::vector<StockData> &data, int window) {
    std::vector<double> sma(data.size(), 0);

    for (size_t i = window - 1; i < data.size(); i++) {
        double sum = 0;
        for (int j = 0; j < window; j++) {
            sum += data[i - j].close;
        }
        sma[i] = sum / window;
    }

    return sma;
}

// Function to calculate the Relative Strength Index (RSI)
std::vector<double> calculateRSI(const std::vector<StockData> &data, int period = 14) {
    std::vector<double> rsi(data.size(), 0);

    for (size_t i = period; i < data.size(); i++) {
        double gain = 0, loss = 0;

        // Calculate the gains and losses for the period
        for (int j = 1; j <= period; j++) {
            double change = data[i - j].close - data[i - j - 1].close;
            if (change > 0) gain += change;
            else loss -= change;
        }

        double avgGain = gain / period;
        double avgLoss = loss / period;

        // Avoid division by zero
        if (avgLoss == 0) {
            rsi[i] = 100;
        } else {
            double rs = avgGain / avgLoss;
            rsi[i] = 100 - (100 / (1 + rs));
        }
    }

    return rsi;
}

// Function to display the results
void displayAnalysis(const std::vector<StockData> &data, const std::vector<double> &sma, const std::vector<double> &rsi) {
    std::cout << "Date\t\tClose\tSMA_50\tRSI_14" << std::endl;

    for (size_t i = 0; i < data.size(); i++) {
        std::cout << data[i].date << "\t" << data[i].close << "\t";
        if (i >= 49) std::cout << sma[i] << "\t";
        else std::cout << "N/A\t";

        if (i >= 13) std::cout << rsi[i] << "\n";
        else std::cout << "N/A\n";
    }
}

int main() {
    std::string filename = "stock_data.csv"; // Input CSV file with stock data

    // Read stock data from the CSV file
    std::vector<StockData> data = readStockData(filename);

    // Calculate Simple Moving Average (SMA) with a window of 50 days
    std::vector<double> sma = calculateSMA(data, 50);

    // Calculate Relative Strength Index (RSI) with a period of 14
    std::vector<double> rsi = calculateRSI(data, 14);

    // Display the analysis results
    displayAnalysis(data, sma, rsi);

    return 0;
}
