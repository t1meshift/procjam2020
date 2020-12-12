#include <SFML/Graphics.hpp>
#include <gameManagers/SceneManager.h>
#include <scenes/TestScene.h> // FIXME

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "PROCJAM 2020");

    // TODO init loading scene
    // TODO init sound system
    auto& sceneManager = pj::gameManagers::SceneManager::instance();
    sceneManager.addScene(std::move(std::make_unique<pj::scenes::TestScene>()),
                          "testScene");
    sceneManager.switchScene("testScene");

    sf::Clock clk;
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    break;
                case sf::Event::LostFocus:
                    break;
                case sf::Event::GainedFocus:
                    break;
                case sf::Event::TextEntered:
                    break;
                case sf::Event::KeyPressed:
                    break;
                case sf::Event::KeyReleased:
                    break;
                case sf::Event::MouseWheelMoved:
                    break;
                case sf::Event::MouseWheelScrolled:
                    break;
                case sf::Event::MouseButtonPressed:
                    break;
                case sf::Event::MouseButtonReleased:
                    break;
                case sf::Event::MouseMoved:
                    break;
                case sf::Event::MouseEntered:
                    break;
                case sf::Event::MouseLeft:
                    break;
                case sf::Event::JoystickButtonPressed:
                    break;
                case sf::Event::JoystickButtonReleased:
                    break;
                case sf::Event::JoystickMoved:
                    break;
                case sf::Event::JoystickConnected:
                    break;
                case sf::Event::JoystickDisconnected:
                    break;
                case sf::Event::TouchBegan:
                    break;
                case sf::Event::TouchMoved:
                    break;
                case sf::Event::TouchEnded:
                    break;
                case sf::Event::SensorChanged:
                    break;
                case sf::Event::Count:
                    break;
            }
        }
        window.clear(sf::Color::Black);

        auto& scene = sceneManager.getCurrentScene();
        auto dt = clk.restart().asMilliseconds() / 1000.0;
        window.setTitle("PROCJAM 2020 | FPS: " + std::to_string(1.0/dt));
        scene.update(dt);
        scene.draw(window);

        window.display();
    }

    return 0;
}
