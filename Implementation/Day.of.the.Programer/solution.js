'use strict';
Object.defineProperty(exports, "__esModule", { value: true });
var fs_1 = require("fs");
process.stdin.resume();
process.stdin.setEncoding('utf-8');
var inputString = '';
var inputLines = [];
var currentLine = 0;
process.stdin.on('data', function (inputStdin) {
    inputString += inputStdin;
});
process.stdin.on('end', function () {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});
function readLine() {
    return inputLines[currentLine++];
}
/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */
function dayOfProgrammer(year) {
    // Write your code here
    if (year === 1918) {
        return "26.09." + year;
    }
    var isLeapYear = false;
    if (year <= 1917 && year % 4 == 0) {
        isLeapYear = true;
    }
    else if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
        isLeapYear = true;
    }
    if (isLeapYear) {
        return "12.09." + year;
    }
    else {
        return "13.09." + year;
    }
}
function main() {
    var ws = (0, fs_1.createWriteStream)(process.env['OUTPUT_PATH']);
    var year = parseInt(readLine().trim(), 10);
    var result = dayOfProgrammer(year);
    ws.write(result + '\n');
    ws.end();
}
