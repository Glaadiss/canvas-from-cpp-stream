const splitJSON = data =>
  data
  .toString()
  .replace(/}{/g, "}#{")
  .split("#");

const { spawn, exec } = require("child_process");
const backend = spawn("./../backend/backend");

backend.stdout.on("error", data => {
  console.log(`error: ${data}`);
});

const on = (desiredEventName, callback) =>
  backend.stdout.on("data", data =>
    splitJSON(data).map(obj => executeAction(desiredEventName, callback, obj))
  );

function executeAction(desiredEventName, callback, data) {
  const { eventName, eventData } = JSON.parse(data);
  // console.log(`received event: ${eventName} with data: ${eventData}`);
  if (eventName === desiredEventName) callback(eventData);
}

process.stdin.resume(); //so the program will not close instantly

function exitHandler(options, err) {
  exec("pkill backend");
  if (options.cleanup) console.log("clean");
  if (err) console.log(err.stack);
  if (options.exit) process.exit();
}

//do something when app is closing
process.on("exit", exitHandler.bind(null, { cleanup: true }));

//catches ctrl+c event
process.on("SIGINT", exitHandler.bind(null, { exit: true }));

// catches "kill pid" (for example: nodemon restart)
process.on("SIGUSR1", exitHandler.bind(null, { exit: true }));
process.on("SIGUSR2", exitHandler.bind(null, { exit: true }));

//catches uncaught exceptions
process.on("uncaughtException", exitHandler.bind(null, { exit: true }));

module.exports = { on };