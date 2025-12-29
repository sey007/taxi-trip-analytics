# NYC Taxi Trip Analytics (C++)

A high-performance C++ program for parsing and analyzing NYC Yellow Taxi trip data (≈13 million rows, ~1 GB CSV).  
This project focuses on I/O efficiency, parsing performance, and clean analytical abstractions, and was optimized 
step-by-step to reduce runtime from minutes to ~22 seconds.

## Features

- Fast CSV parsing (no `stringstream`, no per-field allocations)
- Efficient timestamp parsing and time-based analytics
- Basic statistical analysis over millions of trips
- Release-mode optimized for large-scale data processing

## Dataset

This project uses the **NYC Yellow Taxi Trip Data (January 2015)** obtained from Kaggle:

- Source: NYC Yellow Taxi Trip Data (Kaggle)
- Link: https://www.kaggle.com/datasets/elemento/nyc-yellow-taxi-trip-data
- Size: ~12.75 million rows (~1 GB CSV)

Due to file size and licensing considerations, the raw dataset is **not included** in this repository.

### Reproducing Results

1. Download the dataset from Kaggle (requires a free Kaggle account)
2. Extract the January 2015 CSV file
3. Place it in the following directory:

data/yellow_tripdata_2015-01.csv



## Build Instructions (Windows / Visual Studio)

### Requirements
- Visual Studio 2022
- MSVC compiler
- C++17 enabled

### Build
- Configuration: **Release**
- Platform: **x64**

Then build normally:
Build → Build Solution


## Running

Simply run the generated executable:

taxi-trip-analytics.exe

Example output:
Loading NYC taxi trip data...
Loaded 12748986 trips.

Mean fare: $12.43
Mean trip distance: 2.89 miles
Average speed: 17.6 mph

Average fare by pickup hour:
Hour 8: $13.01 (523456 trips)
Hour 17: $14.22 (612398 trips)

Average tip by passenger count:
1 passengers: $1.86
2 passengers: $2.34


## Performance

| Version | Runtime |
|------|-------|
| Naive CSV parsing (`stringstream`) | > 1 minute |
| Manual tokenization + `stoi/stod` | ~55 seconds |
| Pointer-based parsing + `atoi/atof` | ~30 seconds |
| Release build + reserves + branch removal | **~22 seconds** |

**Compiler:** MSVC Release x64

## Optimization Techniques Used

- Disabled debug logging in Release builds
- `vector::reserve()` to avoid reallocations
- Pointer-based CSV parsing (`char*`)
- `atoi` / `atof` instead of `stoi` / `stod`
- Single-pass parsing (no token vectors)
- Minimal exception usage
- Avoided unnecessary temporaries

## Project Structure

taxi-trip-analytics/
|── Analytics.cpp / .h # Statistical analysis
|── CSVReader.cpp / .h # High-performance CSV ingestion
|── TimeUtilities.cpp / .h # Timestamp parsing and time helpers
|── Trip.cpp / .h # Trip data model
|── main.cpp # Program entry point
|── data/ # CSV files


## Notes

- Parsing speed is now **I/O-bound**, not CPU-bound
- Further gains would require:
  - Memory-mapped files
  - SIMD parsing
  - Multithreaded chunk processing

## Motivation

This project was built to practice **systems-level performance optimization** in C++, with a focus on real-world data sizes — relevant for quantitative research, data engineering, and operations research (IOE/SURE-style work).



