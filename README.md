# Health Data Tracker

## Overview

The Health Data Tracker is a simple C program that allows users to log their health data (glucose levels, systolic blood pressure, and diastolic blood pressure) and generate reports based on the logged data.

## Features

- **Log Health Data**: Append new health data entries to a CSV file.
- **Generate Report**: Create a report summarizing the logged data, including average values.

## Usage

### Command Line Arguments

The program accepts the following command-line arguments:

1. `[glucose] [systolic] [diastolic]` - Add new health data.
2. `p` or `P` - Generate and display a report.
3. `h` or `H` - Display the help message.

### Examples

1. **Log Health Data**
    ```sh
    ./health_tracker 120 130 80
    ```

2. **Generate Report**
    ```sh
    ./health_tracker p
    ```

3. **Display Help**
    ```sh
    ./health_tracker h
    ```

## File Structure

- `healthData.csv`: The CSV file where health data is stored.
- `report.txt`: The generated report file.

## Compilation

To compile the program, use the following command:

```sh
gcc -o health_tracker health_tracker.c


![health_monitor](https://github.com/jhill1971/health_data_tracker/assets/60713038/26284569-8a68-4bde-b4b4-eefd15aadd36)


# MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

