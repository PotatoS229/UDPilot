import './Auth.css'
import {Link} from 'react-router-dom'

const AuthPage = () => {
    return (
        <div className="container">
            <div className="form-box">
                <h1>Добро пожаловать</h1>
                <p className="subtitle">Войдите в свой аккаунт</p>
                <form action="#" method="post">
                    <div className="input-group">
                        <label htmlFor="email">Электронная почта</label>
                        <input type="email" id="email" name="email" placeholder="hello@example.com" required />
                    </div>
                    <div className="input-group">
                        <label htmlFor="password">Пароль</label>
                        <input type="password" id="password" name="password" placeholder="••••••••" required />
                    </div>
                    <div className="options">
                        <label className="checkbox">
                            <input type="checkbox" defaultChecked /> Запомнить меня
                        </label>
                        <a href="#" className="forgot-link">Забыли пароль?</a>
                    </div>
                    <Link to="/menu">
                        <button type="submit" className="btn-primary">Войти</button>
                    </Link>
                </form>
                <p className="switch-text">Нет аккаунта?
                    <a href="#">Зарегистрироваться</a>
                </p>
            </div>
            <div className="circle-bg"></div>
        </div>
    )
}

export default AuthPage;

    