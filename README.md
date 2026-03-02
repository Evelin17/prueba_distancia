@@ -0,0 +1,38 @@
<!DOCTYPE html>
<html>
<head>
  <title>Control LED</title>
  <script src="https://www.gstatic.com/firebasejs/9.23.0/firebase-app-compat.js"></script>
  <script src="https://www.gstatic.com/firebasejs/9.23.0/firebase-database-compat.js"></script>
</head>
<body>
  <h1>Control de LED</h1>
  <button onclick="encender()">Encender</button>
  <button onclick="apagar()">Apagar</button>

  <script>
    // Configuración de Firebase
    const firebaseConfig = {
      apiKey: "AIzaSyCG1-rcAiJR8YLynWvi68CQiHSJ0WsnbR4",
      authDomain: "control-led-fef7a.firebaseapp.com",
      databaseURL: "https://control-led-fef7a-default-rtdb.firebaseio.com",
      projectId: "control-led-fef7a",
      storageBucket: "control-led-fef7a.appspot.com",
      messagingSenderId: "821707980658",
      appId: "1:821707980658:web:b0740c8c6b4243c986e7eb"
    };

    // Inicializar Firebase
    const app = firebase.initializeApp(firebaseConfig);
    const db = firebase.database();

    function encender() {
      db.ref('estado').set(1); // Usa 1 para encender
    }

    function apagar() {
      db.ref('estado').set(0); // Usa 0 para apagar
    }
  </script>
</body>
</html>
