import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MateriasPrimasListComponent } from './materias-primas-list.component';

describe('MateriasPrimasListComponent', () => {
  let component: MateriasPrimasListComponent;
  let fixture: ComponentFixture<MateriasPrimasListComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MateriasPrimasListComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MateriasPrimasListComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
