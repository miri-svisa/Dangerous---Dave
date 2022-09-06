#include"ViewInfo.h"
//#include"Level.h"
//----------------------------------------------------------
ViewInfo::ViewInfo(std::unique_ptr<Player>& pplayr) //:m_key(false)
{
	pplayr->RegisterObserver(*this);
	m_lives = sf::Text("DAVES", Singelton::get_instance().getFont());
	m_lives.setFillColor(m_color);
	m_score = sf::Text("SCORE", Singelton::get_instance().getFont());
	m_score.setFillColor(m_color);
	m_level = sf::Text("LEVEL", Singelton::get_instance().getFont());
	m_level.setFillColor(m_color);
	m_lives.setPosition(sf::Vector2f(0, 0));
	m_score.setPosition(sf::Vector2f(281, 0));
	m_level.setPosition(sf::Vector2f(500, 0));
}
//----------------------------------------------------------------------
void ViewInfo::draw(sf::RenderWindow& window)
{
	window.draw(m_lives);
	window.draw(m_score);
	window.draw(m_level);
}
//----------------------------------------------------------------------------
void ViewInfo::sizeWindow(sf::RenderWindow& window)const
{
	auto viewSizeInfo = sf::Vector2f(window.getSize().x, LENGTHOFINFOVIEW);
	auto viewInfo = sf::View(sf::Vector2f(WIDTH / 2, LENGTHOFINFOVIEW / 2), viewSizeInfo);
	viewInfo.setViewport({ 0.f, 0.f, 1.f, 0.1f });
	window.setView(viewInfo);
}
//----------------------------------------------------------------------------
void ViewInfo::drawTheValues( sf::RenderWindow& window)
{
	auto livesstext = sf::Sprite( Singelton::get_instance().getTexture(dave));
	//auto livesstext = sf::Text(std::to_string(m_daves), Singelton::get_instance().getFont());
	auto scoresstext = sf::Text(std::to_string(m_scores), Singelton::get_instance().getFont());
	auto levelext = sf::Text(std::to_string(m_levels), Singelton::get_instance().getFont());
	//livesstext.setFillColor(m_color);
	scoresstext.setFillColor(m_color);
	levelext.setFillColor(m_color);
	//livesstext.setPosition(sf::Vector2f(130, 0));
	scoresstext.setPosition(sf::Vector2f(130+(5*LENGTHOFCELL), 0));
	levelext.setPosition(sf::Vector2f(500 + (2 * LENGTHOFCELL), 0));
	for (int i = 0; i < m_daves; i++)
	{
		livesstext.setPosition(sf::Vector2f(70+(i*LENGTHOFCELL), 0));
		window.draw(livesstext);
	}
	window.draw(scoresstext);
	window.draw(levelext);
	if (m_gun)
	{
		auto gan=sf::Sprite(Singelton::get_instance().getTexture(gun));
		//m_Sprite = sf::Sprite(m_picture);
		auto texSize = Singelton::get_instance().getTexture(gun).getSize();
		auto newTexSize = sf::Vector2u(WIDTHOFCELL, LENGTHOFCELL);
		auto scaleX = newTexSize.x * 1.00f / texSize.x;
		auto scaleY = newTexSize.y * 1.00f / texSize.y;
		gan.scale(scaleX, scaleY);
		//m_Sprite.setPosition(Location);
		gan.setPosition(sf::Vector2f(750,0));
		window.draw(gan);
	}
	if (m_key)
	{
		auto gan = sf::Sprite(Singelton::get_instance().getTexture(key));
		//m_Sprite = sf::Sprite(m_picture);
		auto texSize = Singelton::get_instance().getTexture(gun).getSize();
		auto newTexSize = sf::Vector2u(WIDTHOFCELL, LENGTHOFCELL);
		auto scaleX = newTexSize.x * 1.00f / texSize.x;
		auto scaleY = newTexSize.y * 1.00f / texSize.y;
		gan.scale(scaleX, scaleY);
		//m_Sprite.setPosition(Location);
		gan.setPosition(sf::Vector2f(800, 0));
		window.draw(gan);
		window.draw(gan);
	}
}