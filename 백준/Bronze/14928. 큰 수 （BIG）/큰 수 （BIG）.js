const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString();
console.log((BigInt(input) % BigInt("20000303")).toString());