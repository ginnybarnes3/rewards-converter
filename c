[33mcommit f30cb5e67d23a2059d8e021ea1c6cfcb2e1e68be[m[33m ([m[1;36mHEAD[m[33m -> [m[1;32mflow[m[33m, [m[1;31morigin/flow[m[33m, [m[1;31morigin/HEAD[m[33m)[m
Author: josiah <josiah.chapman@gmail.com>
Date:   Sun Jan 29 20:19:04 2023 -0800

    init

[1mdiff --git a/.gitignore b/.gitignore[m
[1mnew file mode 100644[m
[1mindex 0000000..92322c4[m
[1m--- /dev/null[m
[1m+++ b/.gitignore[m
[36m@@ -0,0 +1,2 @@[m
[32m+[m[32m.idea/[m
[32m+[m[32mtarget/[m
[1mdiff --git a/pom.xml b/pom.xml[m
[1mnew file mode 100644[m
[1mindex 0000000..13d21da[m
[1m--- /dev/null[m
[1m+++ b/pom.xml[m
[36m@@ -0,0 +1,25 @@[m
[32m+[m[32m<?xml version="1.0" encoding="UTF-8"?>[m
[32m+[m[32m<project xmlns="http://maven.apache.org/POM/4.0.0"[m
[32m+[m[32m         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"[m
[32m+[m[32m         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">[m
[32m+[m[32m    <modelVersion>4.0.0</modelVersion>[m
[32m+[m
[32m+[m[32m    <groupId>com.vagabondsystems</groupId>[m
[32m+[m[32m    <artifactId>rewards-converter</artifactId>[m
[32m+[m[32m    <version>1.0-SNAPSHOT</version>[m
[32m+[m[32m    <dependencies>[m
[32m+[m[32m        <dependency>[m
[32m+[m[32m            <groupId>org.junit.jupiter</groupId>[m
[32m+[m[32m            <artifactId>junit-jupiter</artifactId>[m
[32m+[m[32m            <version>RELEASE</version>[m
[32m+[m[32m            <scope>test</scope>[m
[32m+[m[32m        </dependency>[m
[32m+[m[32m    </dependencies>[m
[32m+[m
[32m+[m[32m    <properties>[m
[32m+[m[32m        <maven.compiler.source>19</maven.compiler.source>[m
[32m+[m[32m        <maven.compiler.target>19</maven.compiler.target>[m
[32m+[m[32m        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>[m
[32m+[m[32m    </properties>[m
[32m+[m
[32m+[m[32m</project>[m
\ No newline at end of file[m
[1mdiff --git a/readme.md b/readme.md[m
[1mnew file mode 100644[m
[1mindex 0000000..f2236c3[m
[1m--- /dev/null[m
[1m+++ b/readme.md[m
[36m@@ -0,0 +1,2 @@[m
[32m+[m[32m# :airplane: Credit Rewards Converter :airplane:[m
[32m+[m[32mThis is the project repo for the JPMC Software Engineering Lite Program, consult the program instructions for more information.[m
\ No newline at end of file[m
[1mdiff --git a/src/main/java/RewardsConverter.java b/src/main/java/RewardsConverter.java[m
[1mnew file mode 100644[m
[1mindex 0000000..2c35d11[m
[1m--- /dev/null[m
[1m+++ b/src/main/java/RewardsConverter.java[m
[36m@@ -0,0 +1,20 @@[m
[32m+[m[32mimport java.util.Scanner;[m
[32m+[m
[32m+[m[32mpublic class RewardsConverter {[m
[32m+[m[32m    public static void main(String[] args) {[m
[32m+[m[32m        var scanner = new Scanner(System.in);[m
[32m+[m[32m        System.out.println("Welcome to the Credit Card Rewards Converter!");[m
[32m+[m[32m        System.out.println("Please enter a cash value to convert to airline miles: ");[m
[32m+[m[32m        var input_value = scanner.nextLine();[m
[32m+[m[32m        double cashValue;[m
[32m+[m[32m        try {[m
[32m+[m[32m            cashValue = Double.parseDouble(input_value);[m
[32m+[m[32m        } catch (NumberFormatException exception) {[m
[32m+[m[32m            System.out.println("Could not parse input value as a double, exiting");[m
[32m+[m[32m            return;[m
[32m+[m[32m        }[m
[32m+[m[32m        System.out.println("converting $" + input_value + " to miles");[m
[32m+[m[32m        var rewardsValue = new RewardValue(cashValue);[m
[32m+[m[32m        System.out.println("$" + input_value + " is worth " + rewardsValue.getMilesValue() + " miles");[m
[32m+[m[32m    }[m
[32m+[m[32m}[m
\ No newline at end of file[m
[1mdiff --git a/src/test/java/RewardValueTests.java b/src/test/java/RewardValueTests.java[m
[1mnew file mode 100644[m
[1mindex 0000000..b3a78de[m
[1m--- /dev/null[m
[1m+++ b/src/test/java/RewardValueTests.java[m
[36m@@ -0,0 +1,30 @@[m
[32m+[m[32mimport org.junit.jupiter.api.Test;[m
[32m+[m
[32m+[m[32mimport static org.junit.jupiter.api.Assertions.assertEquals;[m
[32m+[m
[32m+[m[32mpublic class RewardValueTests {[m
[32m+[m
[32m+[m[32m    @Test[m
[32m+[m[32m    void create_with_cash_value() {[m
[32m+[m[32m        double cashValue = 100;[m
[32m+[m[32m        var rewardValue = new RewardValue(cashValue);[m
[32m+[m[32m        assertEquals(cashValue, rewardValue.getCashValue());[m
[32m+[m[32m    }[m
[32m+[m
[32m+[m[32m    @Test[m
[32m+[m[32m    void create_with_miles_value() {[m
[32m+[m[32m        int milesValue = 10000;[m
[32m+[m[32m        var rewardValue = new RewardValue(milesValue);[m
[32m+[m[32m        assertEquals(milesValue, rewardValue.getMilesValue());[m
[32m+[m[32m    }[m
[32m+[m
[32m+[m[32m    @Test[m
[32m+[m[32m    void convert_from_cash_to_miles() {[m
[32m+[m[32m        assert false;[m
[32m+[m[32m    }[m
[32m+[m
[32m+[m[32m    @Test[m
[32m+[m[32m    void convert_from_miles_to_cash() {[m
[32m+[m[32m        assert false;[m
[32m+[m[32m    }[m
[32m+[m[32m}[m
