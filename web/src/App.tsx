import './App.css';
import MenuPage from '../pages/Menu/Menu.tsx';
import AuthPage from '../pages/Auth/Auth.tsx';
import {BrowserRouter as Router, Routes, Route} from "react-router-dom";
function App() {
  return (
    <Router>
          <Routes>
              <Route path="/menu" element={<MenuPage />} />
              <Route path="/auth" element={<AuthPage />} />
          </Routes>
      </Router>
  )
}

export default App
