const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().trim().split("\n");
input.slice(1).forEach(arr => {
    const [d, f, p] = arr.split(" ").map(Number);
    console.log("$" + (d * f * p).toFixed(2));
})