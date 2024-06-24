#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "healthData.csv"

// Function Prototypes
void display_help();
void append_data(int glucose, int systolic, int diastolic);
void generate_report();

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Error: Missing Command-line arguments.\n");
		display_help();
		return 1;
	}
	
	if ((strcmp(argv[1], "h") == 0) || (strcmp(argv[1], "H") ==  0)){
		display_help();
	} else if ((strcmp(argv[1], "p") == 0) || (strcmp(argv[1], "P") ==  0)){
		generate_report();
	} else {
		if (argc !=4) {
			fprintf(stderr, "Error: Incorrect number of arguments for health data.\n");
			display_help();
			return 1;
		}
	int glucose = atoi(argv[1]);
	int systolic = atoi(argv[2]);
	int diastolic = atoi(argv[3]);

	append_data(glucose, systolic, diastolic);
	}
	return 0;
}

void display_help()
{
	printf("Usage:\n");
	printf("    [glucose] [systolic] [diastolic] 	- add new health data.\n");
	printf("    p or P 				- Generate and display a report.\n");
	printf("    h or H				- Display this help message.\n");
}

void append_data(int glucose, int systolic, int diastolic)
{
	FILE *file = fopen(FILENAME, "a");
	if (file == NULL){
	fprintf(stderr, "Error: Could not open file %s.\n", FILENAME);
	return;
	}

	// Get current date
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char date[20];
	sprintf(date, "%02d/%02d/%04d", tm.tm_mon+1,tm.tm_mday,tm.tm_year+1900);
	
	// Append data to CSV
	fprintf(file, "%s,%d,%d,%d\n", date, glucose, systolic, diastolic);
	
	fclose(file);
	printf("Data appended successfully\n");
}

void generate_report()
{
	FILE *file = fopen(FILENAME, "r");
	if (file == NULL){
	fprintf(stderr,"Error: Could not open file %s\n", FILENAME);
	return;
	}
	char line[128];
	int count = 0;
	int total_glucose = 0;
	int total_systolic = 0;
	int total_diastolic = 0;
	
	// Read and process CSV data
	while(fgets(line, sizeof(line), file)){
		char date[20];
		int glucose, systolic, diastolic;
		sscanf(line, "%[^,],%d,%d,%d", date, &glucose, &systolic, &diastolic);

		total_glucose += glucose;
		total_systolic += systolic;
		total_diastolic += diastolic;
		count ++;
	}
	
	fclose(file);
	
	if (count == 0){
		printf("No data available to generate report\n");
		return;
	}

	// Calculate averages
	double average_glucose = (double) total_glucose/count;
	double average_systolic = (double) total_systolic/count;
	double average_diastolic = (double) total_diastolic/count;

	// Generate Report
	FILE *report_file = fopen("report.txt", "w");
	if (report_file == NULL){
		fprintf(stderr, "Error: Could not create report file\n");
		return;
	}
	
	fprintf(report_file,"Health Data Report\n");
	fprintf(report_file,"==================\n\n");
	fprintf(report_file,"Date       | Glucose  | Blood Pressure\n");
	fprintf(report_file,"-----------|----------|---------------\n");

	file = fopen(FILENAME, "r");
	while (fgets(line, sizeof(line), file)){
		char date[20];
		int glucose, systolic, diastolic;
		sscanf(line, "%[^,],%d,%d,%d", date, &glucose, &systolic, &diastolic);
		fprintf(report_file, "%s | %8d | %d/%d\n", date, glucose, systolic, diastolic);
	}
	fclose(file);
	
	fprintf(report_file,"Average Glucose: %.2f\n", average_glucose);
	fprintf(report_file,"Average Blood Pressure: %.0f/%.0f\n",average_systolic, average_diastolic);
	fprintf(report_file,"\n");

	fclose(report_file);
	printf("Report generated successfully.\n");

}
