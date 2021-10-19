#include "mushroom.h"

mushroom::mushroom()
{
    this->x  = 10;
    this->y = 20;
    this->maxMushroomNum = 190;
    this->cells();
    this->initMushroomTexture();
    this->initMushroomSprite();

}

void mushroom::initMushroomTexture()
{
    //Load a texture from a file
    if(!this->mushroomTexture_.loadFromFile("data/mushroom_.png"))
    {
        std::cout<<"ERROR::MUSHROOM::INITMUSHROOMTEXTURE:: Could not load texture file"<<"\n";
    }
}

void mushroom::cells()
{
    auto width = 800.f;
    auto height = 400.f;
    auto cellSizeX = 20.f;
    auto cellSizeY = 20.f;
    int columnsNum =  width/cellSizeX;
    int rowsNum =  height/cellSizeY;


    auto numberOfCells = rowsNum*columnsNum;
    //std::cout<<numberOfCells<<std::endl;

    Position pstn;


      auto i = 0, j = 0;
      while(i<=width-cellSizeY)
    {
        pstn.x = i;
        while(j<=height-cellSizeX)
        {
            pstn.y = j;
            this->mushPositions.push_back(pstn);
            j += cellSizeX;
        }
        i += cellSizeY;
        j = 0;
    }




    for(auto i = 1; i <= numberOfCells; i++)
    {
        this->Cell[i] = false;
        this->cellCentre[i] = this->mushPositions[i];
    }



}


void mushroom::Mushrooms()
{
    //width = 600, height =  800
    auto rows = 800;
    auto columns = 600;
    Position pstn;
    for(auto i = 0; i < rows; i+3)
    {
        pstn.x = i;
        for(auto j = 0; j < columns; j+3)
        {
            pstn.y = j;
            this->mushPositions.push_back(pstn);
        }
    }


}

mushroom::~mushroom()
{

}

void mushroom::initMushroomSprite()
{
    srand(time(0));
    this->mushroomSprite_.setTexture(this->mushroomTexture_);
    this->mushroomSprite_.scale(0.1f,0.1f);
    std::vector<int> cellNo;



    for(auto i = 0; i<maxMushroomNum; i++)
    {
        this->mushroomSprites.push_back(mushroomSprite_);
    }

    for(auto i = 0; i<maxMushroomNum; i++)
    {


        auto cell_ =  rand()%this->cellCentre.size()+ 1;
        auto centr = this->cellCentre[cell_];
        while(Cell[cell_] == true)
        {
            cell_ =  rand()%this->cellCentre.size()+ 1;
        }
        auto x = centr.x;
        auto y = centr.y;

        cellNo.push_back(cell_);
      mushroomSprites[i].setPosition(x,y);
      Cell[cell_] = true;

    }

    auto temp = 0;
    for(auto i = 0; i < cellNo.size();i++)
    {
        temp = cellNo[i];
        for(auto j = i+1; j < cellNo.size(); j++ )
        {
            if(cellNo[j] == temp)
            {
                std::cout<<"Cell Number: "<<temp<<" is repeated"<<std::endl;
            }

        }

    }


}


void mushroom::render(sf::RenderTarget* target)
{
    for(auto i = 0; i<this->maxMushroomNum; i++)
    {
        target->draw(this->mushroomSprites[i]);
    }
}
