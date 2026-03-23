import './App.css';
import MenuPage from '../pages/Menu/Menu.tsx';
import ToDo from '../pages/Todo/Todo.tsx';
import {BrowserRouter as Router, Routes, Route} from "react-router-dom";
function App() {
  return (
    <Router>
          <Routes>
              <Route path="/menu" element={<MenuPage />} />
              <Route path="/ToDo" element={<ToDo />}></Route>
          </Routes>
      </Router>
  )
}

export default App
