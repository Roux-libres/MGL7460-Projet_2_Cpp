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
	parseFile("../test_files/uptime_file.txt");
	// TODO
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestParseTime, ParseTime) {
	// TODO
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestDisplayTime, DisplayTime) {
	// TODO
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}