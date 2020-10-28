#include "pch.h"
#include "../MGL7460_Projet_2_Cpp/MGL7460_Projet_2_Cpp.cpp"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestTimeStruct, CreateStruct) {
	TIME time;
	int expected_days(276);
	int expected_hours(12);
	int expected_minutes(36);

	time.days = expected_days;
	time.hours = expected_hours;
	time.minutes = expected_minutes;

	EXPECT_EQ(time.days, expected_days);
	EXPECT_EQ(time.hours, expected_hours);
	EXPECT_EQ(time.minutes, expected_minutes);
}

TEST(TestReadFile, ReadFile) {
	EXPECT_EQ("Test success", readFile("../test_files/test_file.txt"));
}

TEST(TestReadFile, ReadNonExistentFile) {
	EXPECT_EQ("", readFile("../test_files/non_existent_file.txt"));
}

TEST(TestReadFile, ReadEmptyFile) {
	EXPECT_EQ("", readFile("../test_files/empty_file.txt"));
}

TEST(TestParseFile, ParseFile) {
	string* expectedResult = new string[2];
	expectedResult[0] = "15005117.05";
	expectedResult[1] = "6945200.26";

	string* actualResult = new string[2];
	actualResult = parseFile("../test_files/uptime_file.txt");

	EXPECT_EQ(expectedResult, actualResult);
}

TEST(TestParseTime, ParseTime) {
	TIME expectedResult;
	expectedResult.days = 173;
	expectedResult.hours = 16;
	expectedResult.minutes = 5;

	TIME actualResult = parseTime("15005117.05");

	EXPECT_EQ(expectedResult.days, actualResult.days);
	EXPECT_EQ(expectedResult.hours, actualResult.hours);
	EXPECT_EQ(expectedResult.minutes, actualResult.minutes);
}