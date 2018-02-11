function splitJSON(data) {
  return data
    .toString()
    .replace(/}{/g, "}#{")
    .split("#");
}

const { spawn } = require("child_process");
const backend = spawn("./../backend2/backend");

backend.stdout.on("error", data => {
  console.log(`error: ${data}`);
});

const on = (desiredEventName, callback) =>
  backend.stdout.on("data", data =>
    splitJSON(data).map(obj => executeAction(desiredEventName, callback, obj))
  );

function executeAction(desiredEventName, callback, data) {
  const { eventName, eventData } = JSON.parse(data);
  console.log(`received event: ${eventName} with data: ${eventData}`);
  if (eventName === desiredEventName) callback(eventData);
}

module.exports = { on };