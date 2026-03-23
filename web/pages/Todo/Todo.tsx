import './TodoList.css'
import {Link} from 'react-router-dom'
// import {Redux} from 'redux'
import MenuButton from '../../components/MenuButton/MenuButton.tsx'

const TodoList = () => {
    return (
        <div className="dashboard-card">
            <div className="welcome-header">
                <h1>📋ToDo List</h1>
                <p>UDPilot • выберите модуль для настройки</p>
            </div>
            <div className="main-layout">
                

                <aside className="menu-aside">
                    <h2>📋 Меню возможностей</h2>
                    <div className="menu-grid">

                        <Link 
                            to="/menu" 
                            style={{ textDecoration: 'none' }}
                        >
                            <MenuButton index={1} name={"⚙️ Панель управления"}></MenuButton>
                        </Link>

                        <MenuButton index={2} name={"🛠 Свои сервера"}></MenuButton>

                        <MenuButton index={3} name={"🚀 UDP-тюнинг"}></MenuButton>

                        <MenuButton index={4} name={"📊 Визуализация в реальном времени"}></MenuButton>

                        <MenuButton index={5} name={"📋 Логи"}></MenuButton>

                        <MenuButton index={6} name={"🔧 Настройки"}></MenuButton>
                        
                        <a 
                            href="https://t.me/@PotatoS229" 
                            target="_blank" 
                            rel="noopener noreferrer"
                            style={{ textDecoration: 'none' }}
                        >
                            <MenuButton index={7} name={"💬 Telegram"} />
                        </a>

                        <a 
                            href="https://github.com/PotatoS229/UDPilot" 
                            target="_blank" 
                            rel="noopener noreferrer"
                            style={{ textDecoration: 'none' }}
                        >
                            <MenuButton index={8} name={"⭐ Поставить звезду на GitHub"} />
                        </a>
                        <Link 
                            to="/todo" 
                            style={{ textDecoration: 'none' }}
                        >
                            <MenuButton index={9} name={"📋ToDo list"}></MenuButton>
                        </Link>
                    </div>
                </aside>


                {/* основной контент */}
                <div className="content-preview">

                </div>

            </div>
            
            <div className="footer-links">
                <span>© 2025 UDPilot</span>
                <span>
                    <Link to='/auth'>🔄 Сменить профиль</Link> • <Link to="/">Настройки</Link>
                </span>
            </div>

        </div>
        
    )
}
export default TodoList;