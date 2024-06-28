const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().trim();
const universities = [
    {
        solved: 12,
        penalty: 1600
    },
    {
        solved: 11,
        penalty: 894
    },
    {
        solved: 11,
        penalty: 1327
    },
    {
        solved: 10,
        penalty: 1311
    },
    {
        solved: 9,
        penalty: 1004
    },
    {
        solved: 9,
        penalty: 1178
    },
    {
        solved: 9,
        penalty: 1357
    },
    {
        solved: 8,
        penalty: 837
    },
    {
        solved: 7,
        penalty: 1055
    },
    {
        solved: 6,
        penalty: 556
    },
    {
        solved: 6,
        penalty: 773
    },
];

console.log(universities[input - 1].solved + " " + universities[input - 1].penalty);