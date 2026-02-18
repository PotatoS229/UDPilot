import './Menu.css';
import {Link} from 'react-router-dom'

const MenuPage = () => {
    return (
    <div className="dashboard-card">
        <div className="welcome-header">
            <h1>⚙️ Панель управления</h1>
            <p>RaaS Service • выберите модуль для настройки</p>
        </div>
        <div className="main-layout">

            <aside className="menu-aside">
                <h2>📋 Меню возможностей</h2>
                <div className="menu-grid">

                    <div className="menu-btn" role="button">
                        <span>1.</span> Низкоуровневые сетевые взаимодействия (raw sockets, манипуляция пакетами)
                    </div>

                    <div className="menu-btn" role="button">
                        <span>2.</span> Полиморфная эвазия (Proteus-режим) — динамическое переключение протоколов
                    </div>

                    <div className="menu-btn" role="button">
                        <span>3.</span> Impersonation Engine — имитация человеческого поведения
                    </div>

                    <div className="menu-btn" role="button">
                        <span>4.</span> Автономный Red Team Assistant — принятие решений на основе контекста и построение цепочек атак
                    </div>

                    <div className="menu-btn" role="button">
                        <span>5.</span> OSINT-движок — интеграция с Shodan, GitHub и поиск утечек
                    </div>

                    <div className="menu-btn" role="button">
                        <span>6.</span> C2-фреймворк с P2P сетью агентов
                    </div>

                    <div className="menu-btn" role="button">
                        <span>7.</span> Безопасный режим (песочница, прогноз урона)
                    </div>

                    <div className="menu-btn" role="button">
                        <span>8.</span> Интеграции и отчетность (экспорт в Jira, SIEM, генерация доказательной базы)
                    </div>

                    <div className="menu-btn" role="button">
                        <span>9.</span> DevOps и инфраструктура (оркестрация агентов, масштабирование)
                    </div>

                    <div className="menu-btn" role="button">
                        <span>10.</span> Дашборд статистики
                    </div>

                    <div className="menu-btn" role="button">
                        <span>11.</span> Панель управления атаками
                    </div>

                    <div className="menu-btn" role="button">
                        <span>12.</span> Визуализация графа атак с предиктивными векторами
                    </div>
                </div>
            </aside>


            <div className="content-preview">
                <div className="placeholder-icon">📊</div>
                <h3>Сводка по выбранному модулю</h3>
                <p>Здесь появится интерфейс настройки, визуализация или результаты работы модуля, выбранного слева. Используйте меню для навигации.</p>
                

                <div className="mock-stat">
                    <div className="mock-stat-item">
                        <div className="label">активные агенты</div>
                        <div className="value">18</div>
                    </div>
                    <div className="mock-stat-item">
                        <div className="label">задач в очереди</div>
                        <div className="value">7</div>
                    </div>
                    <div className="mock-stat-item">
                        <div className="label">поверхность</div>
                        <div className="value">143</div>
                    </div>
                </div>

            </div>
        </div>


        <div className="footer-links">
            <span>© 2025 RaaS Service</span>
            <span>
                <Link to='/auth'>🔄 Сменить профиль</Link> • <Link to="/">Настройки</Link>
            </span>
        </div>
    </div>
    )
}

export default MenuPage;


  