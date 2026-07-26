onmessage = async function (event) {
  try {
    const response = await fetch("https://dummyapi.com/users");
    const users = await response.json();

    if (!users || users.length === 0) {
      postMessage({ error: "No users returned from the API" });
      return; 
    }
    const lines = users.map(function (user) {
      const status = user.active ? "Active" : "Inactive";
      return user.name + " - " + status;
    });
    postMessage({ data: lines });

  } catch (err) {
    postMessage({ error: "Something went wrong: " + err.message });
  }
};


// as the api is just a dummy api, so putting in a temporary test with hardcoded data
// commen tout the below code and uncomment the above code to test

onmessage = async function (event) {
  try {
    const users = [
      { name: "Tom", active: true },
      { name: "John", active: false },
      { name: "Jerry", active: true }
    ];

    if (!users || users.length === 0) {
      postMessage({ error: "No users returned from the API" });
      return;
    }

    const lines = users.map(function (user) {
      const status = user.active ? "Active" : "Inactive";
      return user.name + " - " + status;
    });

    postMessage({ data: lines });
  } catch (err) {
    postMessage({ error: "Something went wrong: " + err.message });
  }
};
